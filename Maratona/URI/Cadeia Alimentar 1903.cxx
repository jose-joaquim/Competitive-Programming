#include <iostream>
#include <cstdio>
#include <vector>

#define VISITED 1
#define UNVISITED -1

using namespace std;

typedef vector<int> vi;
vi componentes;
vi dfs_num;
vector<vi> AdjList;

int vetMarcado(){
	for(int i = 0; i < (int)dfs_num.size(); i++){
		if(dfs_num[i] == UNVISITED){
			return i;
		}
	}
	return -1;
}

void dfs(int u, int comp){
	componentes[u] = comp;
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int)AdjList[u].size(); i++){
		int v = AdjList[u][i];		
		if(dfs_num[v] == UNVISITED){
			dfs(v, comp);
		}
	}	
}

void dfs_comp(){
	int comp = 0;
	int v = vetMarcado();
	while(v != -1){
		//printf("v eh %d\n", v);
		dfs(v, comp);
		comp++;
		v = vetMarcado();			
	}
}


int main(int argc, char **argv)
{
	int V, E, u, v;
	scanf("%d %d", &V, &E);
	AdjList.assign(V, vi());
	componentes.assign(V, -1);
	dfs_num.assign(V, UNVISITED);
	for(int i = 0; i < V; i++){
		scanf("%d %d", &u, &v);
		AdjList[u-1].push_back(v-1);
	}
	dfs_comp();
	for(int i = 0; i < (int)componentes.size(); i++){
		printf("%d ", componentes[i]);
	}
	puts("");
	return 0;
}

