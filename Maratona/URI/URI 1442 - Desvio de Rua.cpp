//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1442


#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <map>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;

int n, m, dfsNumberCount, pontes, nSCC, visitei;
vector<vi> AdjList1, AdjList2;
vi dfs_num, dfs_low, visited, S, dfs_parent, articulation_vertex, componente;
int dfsRoot, rootChildren;

void findBridges(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCount++;
	//puts("slkdas");
	for(int j = 0; j < (int) AdjList2[u].size(); j++){
		int v = AdjList2[u][j];
		//puts("oi");
		if(dfs_num[v] == UNVISITED){
			dfs_parent[v] = u;
			if(dfsRoot == u) rootChildren++;
			
			findBridges(v);
			
			if(dfs_low[v] >= dfs_num[u]){
				articulation_vertex[u] = true;
			}
			if(dfs_low[v] > dfs_num[u]){
				//printf("%d e %d eh uma ponte\n"
				if(componente[v] != componente[u])	pontes++;
			}
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}	
	}
}

void tarjanSCC(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCount++;
	S.push_back(u);
	visited[u] = 1;
	for(int j = 0; j < (int) AdjList1[u].size(); j++){
		int v = AdjList1[u][j];
		if(dfs_num[v] == UNVISITED){
			tarjanSCC(v);
		}
		if(visited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	
	if(dfs_low[u] == dfs_num[u]){
		++nSCC;
		//printf("SCC %d:", ++nSCC);
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			componente[v] = nSCC;
			//printf(" %d", v+1);
			if(u == v) break;
		}
		//puts("");
	}
}

void dfs(int u){
	dfs_num[u] = VISITED;
	visitei++;
	for(int j = 0; j < (int) AdjList2[u].size(); j++){
		int v = AdjList2[u][j];
		if(dfs_num[v] == UNVISITED){
			dfs(v);
		}
	}
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &n, &m) != EOF){
		AdjList1.assign(n, vi());
		AdjList2.assign(n, vi());
		componente.resize(n);
		for(int i = 0; i < m; i++){
			int u, v, z;
			scanf("%d %d %d", &u, &v, &z);
			if(i > 0){
				AdjList1[u-1].push_back(v-1);
				
				//if(i > 0){
					AdjList2[v-1].push_back(u-1);
					AdjList2[u-1].push_back(v-1);
				//}
				
				if(z == 2) AdjList1[v-1].push_back(u-1);
			}
		}
		
		visitei = 0;
		dfs_num.assign(n, UNVISITED);
		dfs(0);
		if(visitei < n){
			//printf("visited %d\n", visitei);
			puts("*");
			continue;
		}else{
			dfs_num.assign(n, UNVISITED); dfs_low.assign(n, 0); visited.assign(n, 0);
			dfsNumberCount = nSCC = 0;
			for(int i = 0; i < n; i++){
				if(dfs_num[i] == UNVISITED) tarjanSCC(i);
			}
			if(nSCC == 1){
				puts("-");
				continue;
			}
		}
		
		dfsNumberCount = 0; dfs_num.assign(n, UNVISITED);
		dfs_low.assign(n, 0); dfs_parent.assign(n, 0);
		articulation_vertex.assign(n, 0);
		pontes = 0;
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == UNVISITED){
				dfsRoot = i; rootChildren = 0; findBridges(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		
		//printf("%d pontes\n", pontes);
		if(pontes > 0){
			puts("2");
		}else{
			puts("1");
		}
		
		
	}
	return 0;
}

