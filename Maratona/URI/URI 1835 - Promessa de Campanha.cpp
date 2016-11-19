//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1835

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

#define VISITED 1
#define UNVISITED -1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num, visited, dfs_low, S;
int n, m, dfsNumberCount, numSCC;

void tarjanSCC(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCount++;
	S.push_back(u);
	visited[u] = 1;
	for(int j = 0; j < (int) AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED){
			tarjanSCC(v);
		}
		if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	
	if(dfs_low[u] == dfs_num[u]){
		//printf("SCC %d:", ++numSCC);
		++numSCC;
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
	int ct;
	scanf("%d", &ct);
	for(int q = 1; q <= ct; q++){
		scanf("%d %d", &n, &m);
		AdjList.assign(n, vi());
		for(int i = 0; i < m; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[u-1].push_back(v-1);
			AdjList[v-1].push_back(u-1);
		}
		dfs_num.assign(n, UNVISITED);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		dfsNumberCount = numSCC = 0;
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == UNVISITED){
				tarjanSCC(i);
			}
		}
		printf("Caso #%d: ", q);
		if(numSCC - 1 == 0){
			printf("a promessa foi cumprida\n");
		}else{
			printf("ainda falta(m) %d estrada(s)\n", numSCC - 1);
		}
	}
	return 0;
}

