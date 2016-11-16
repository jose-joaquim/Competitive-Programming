#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;

int main(int argc, char **argv)
{
	int ct;
	cin >> ct;
	for(int l = 0; l < ct; l++){
		int N, E, T, M;
		cin >> N >> E >> T >> M;
		AdjList.assign(N, vii());
		for(int i = 0; i < M; i++){
			int u, v, w;
			cin >> u >> v >> w;
			AdjList[v-1].push_back(ii(u-1, w));
		}
		int total = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		vi dist(N, INF); dist[E-1] = 0;
		pq.push(ii(0, E-1));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if(d > dist[u]) continue;
			for(int j = 0; j < (int) AdjList[u].size(); j++){
				ii v = AdjList[u][j];
				if(dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}
		for(int i = 0; i < N; i++){
			if(dist[i] <= T){
				total++;
			}
		}
		printf("%d\n", total);
		if(l < ct-1) printf("\n");
	}
	return 0;
}

