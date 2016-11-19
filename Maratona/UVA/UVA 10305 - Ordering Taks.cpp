//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;
vi dfs_num;
vi ts;
vector<vi> AdjList;


void dfs(int u){
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int)AdjList[u].size(); i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == UNVISITED){
			dfs(v);
		}
	}
	ts.push_back(u);
}

int main(int argc, char **argv)
{
	int V, E;
	while(scanf("%d %d", &V, &E) && (V||E)){
		dfs_num.assign(V, UNVISITED);
		AdjList.assign(V, vi());
		int a, b;
		for(int i = 0; i < E; i++){
			scanf("%d %d", &a, &b);
			AdjList[a-1].push_back(b-1);
		}		
		ts.clear();		
		for(int i = 0; i < V; i++){			
			if(dfs_num[i] == UNVISITED){
				dfs(i);
			}
		} 
		reverse(ts.begin(), ts.end());
		for(int i = 0; i < (int)ts.size(); i++){
			printf("%d ", ts[i]+1);
		}
		puts("");
		/*for(int i = (int)ts.size() - 1; i >= 0; i--){
			printf(" %d", ts[i]);
		}*/
	}
	return 0;
}

