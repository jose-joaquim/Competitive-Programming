#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#include <vector>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, c, k;
vector<vii> AdjList;

int main(int argc, char **argv)
{
	while(scanf("%d %d %d %d", &n, &m, &c, &k) && (n || m || c || k)){
		AdjList.assign(n, vii());
		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			AdjList[u].push_back(ii(v, w));
			AdjList[v].push_back(ii(u, w));
		}
		vi dist(n, INF); dist[k] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, k));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first; int u = front.second;
			if(d > dist[u]) continue;
			for(int j = 0; j < (int) AdjList[u].size(); j++){
				ii v = AdjList[u][j];
				if(u < c){
					if(v.first != u + 1) continue;
					if(dist[v.first] > v.second + dist[u]){
						dist[v.first] = v.second + dist[u];
						pq.push(ii(dist[v.first], v.first));
					}
				}else{
					if(dist[v.first] > v.second + dist[u]){
						dist[v.first] = v.second + dist[u];
						pq.push(ii(dist[v.first], v.first));
					}
				}
			}
		}
		printf("%d\n", dist[c-1]);
	}
	return 0;
}

