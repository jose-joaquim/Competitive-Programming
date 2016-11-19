//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1790


#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

#define VISITED 1	
#define UNVISITED -1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int C, P, dfsNumberCount, dfsRoot, rootChildren;
int bridges;

void dfsModified(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCount++;
	for(int j = 0; j < (int) AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED){
			dfs_parent[v] = u;
			if(dfsRoot == u) rootChildren++;
			
			dfsModified(v);
			
			if(dfs_low[v] >= dfs_num[u]){
				articulation_vertex[u] = true;
			}
			if(dfs_low[v] > dfs_num[u]){
				//printf("ponte na aresta %d %d\n", u+1, v+1);
				//printf("oieie %d %d\n", u+1, v);
				bridges++;
			}
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}	
	}
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &C, &P) != EOF){
		AdjList.assign(C, vi());
		for(int i = 0; i < P; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[u-1].push_back(v-1);
			AdjList[v-1].push_back(u-1);
		}
		bridges = 0;
		dfsNumberCount = 0;
		dfs_num.assign(C, UNVISITED);
		dfs_low.assign(C, 0);
		dfs_parent.assign(C, 0);
		articulation_vertex.assign(C, 0);
		for(int i = 0; i < C; i++){
			if(dfs_num[i] == UNVISITED){
				dfsRoot = i; rootChildren = 0; dfsModified(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		printf("%d\n", bridges);
	}
	return 0;
}

