#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num, dfs_low, visited, S;
int dfsNumberCount, numSCC;
bool stop;

int tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCount++;
	S.push_back(u);
	visited[u] = 1;
	for(int j  = 0; j < (int) AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED){
			tarjanSCC(v);
		}
		if(visited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	
	if(dfs_low[u] == dfs_num[u]){
		//printf("SCC %d:", ++numSCC);
		int count = 0;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			count++;
			/*printf(" %d", v);*/
			if(u == v) break;
		}
		if(count > 1){
			stop = true;
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int q = 0; q < ct; q++){
		stop = false;
		S.clear();
		int n, m;
		scanf("%d %d", &n, &m);
		AdjList.assign(n, vi());
		for(int i = 0; i < m; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[u-1].push_back(v-1);
		}
		dfs_num.assign(n, UNVISITED);
		dfs_low.assign(n, 0);
		visited.assign(n, 0);
		dfsNumberCount = numSCC = 0;
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == UNVISITED)
				tarjanSCC(i);
		}
		puts(stop ? "SIM" : "NAO");
	}
	return 0;
}
