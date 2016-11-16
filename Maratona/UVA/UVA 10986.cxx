#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <map>

using namespace std;

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vector<ii> > AdjList;

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int l = 1; l <= ct; l++){
		int n, m, S, T;
		map<pair<int, int>, int> weights;
		cin >> n >> m >> S >> T;
		AdjList.assign(n, vector<ii>());
		for(int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			AdjList[u].push_back(make_pair(v, w));
			AdjList[v].push_back(make_pair(u, w));
		}
		vi dist(n, INF); dist[S] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, S));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if(d > dist[u]) continue;
			for(int i = 0; i < (int) AdjList[u].size(); i++){
				ii v = AdjList[u][i];
				if(dist[u] + v.second < dist[v.first]){//v.first significa o vertice destino, enquanto que .second é o peso da aresta
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		dist[T] != INF ? printf("Case #%d: %d\n", l, dist[T]) : printf("Case #%d: unreachable\n", l);
	}
	return 0;
}

