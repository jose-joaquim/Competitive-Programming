//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1900

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int main(int argc, char **argv)
{
	int ct;
	cin >> ct;
	for(int l = 0; l < ct; l++){
		int p, d;
		cin >> p >> d;
		vector<vi> AdjList;
		AdjList.assign(p, vi());
		for(int i = 0; i < d; i++){
			int u, v;
			cin >> u >> v;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		queue<int> q; q.push(0);
		vi dist(p, INF); dist[0] = 0;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int j = 0; j < (int) AdjList[u].size(); j++){
				int v = AdjList[u][j];
				if(dist[v] == INF){
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		for(int i = 1; i < p; i++){
			printf("%d\n", dist[i]);
		}
		if(l < ct-1) printf("\n");
	}
	return 0;
}

