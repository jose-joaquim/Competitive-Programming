//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2391

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
typedef vector <int> vi;

int main(int argc, char **argv)
{
	int V;
	while(scanf("%d", &V) && V != 0){
		int a, b;
		vector<vi> AdjList;
		AdjList.assign(V, vi());
		AdjList.clear();
		while(scanf("%d %d", &a, &b) && (a || b)){
			AdjList[a-1].push_back(b-1);
			AdjList[b-1].push_back(a-1);
		}	
		vi color(V, 1e9);
		queue<int> q; q.push(0);
		color[0] = 0;
		bool isBipartite = true;
		while(!q.empty() && isBipartite){
			int u = q.front(); q.pop();
			for(int j = 0; j < (int)AdjList[u].size(); j++){
				int v = AdjList[u][j];
				if(color[v] == 1e9){
					color[v] = 1 - color[u];
					q.push(v);
				}else if(color[v] == color[u]){
					isBipartite = false;
					break;
				}
			}		
		}	
		puts(isBipartite ? "YES" : "NO");	
	}
	return 0;
}

