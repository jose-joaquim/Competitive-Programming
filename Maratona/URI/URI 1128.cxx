#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num, dfs_low, S, visited;
int V, E, dfsNumberCounter;
int numSCC;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for(int j = 0; j < (int) AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED){
			tarjanSCC(v);
		}
		if(visited[v]){
			dfs_low[u] = min(dfs_low[v], dfs_low[u]);
		}
	}
	
	if(dfs_low[u] == dfs_num[u]){
		numSCC++;
		//printf("SCC %d:", ++numSCC);
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			//printf(" %d", v);
			if(u == v) break;
		}
		//printf("\n");
	}
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &V, &E) && (V || E)){
		numSCC = 0;
		dfsNumberCounter = 0;
		AdjList.assign(V, vi());
		visited.clear();
		S.clear();
		//printf("v eh %d e e eh %d\n", V, E);
		for(int i = 0; i < E; i++){
			int u, v, op;
			scanf("%d %d %d", &u, &v, &op);
			if(op == 1) AdjList[u-1].push_back(v-1);
			else{
				AdjList[u-1].push_back(v-1);
				AdjList[v-1].push_back(u-1);
			}
		}
		dfs_num.assign(V, UNVISITED);
		dfs_low.assign(V, 0);
		visited.assign(V, 0);
		for(int i = 0; i < V; i++){
			if(dfs_num[i] == UNVISITED){
				tarjanSCC(i);
			}
		}
		puts(numSCC <= 1 ? "1" : "0");
	}
	return 0;
}

