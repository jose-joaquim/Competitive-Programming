//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3053

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

#define INF 1000000000
#define UNVISITED -1
#define VISITED 1
#define BLOQUEADO 4

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num, dfs_bloq;
int N;

void dfs(int u, int bloqueado){
	if(u == bloqueado){
		return;
	}
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int) AdjList[u].size(); i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == UNVISITED){
			dfs(v, bloqueado);			
		}
	}
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int l = 1; l <= ct; l++){
		int x;
		scanf("%d", &N);
		AdjList.assign(N, vi());
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				scanf("%d", &x);
				if(x == 1) AdjList[i].push_back(j);
			}
		}
		dfs_num.assign(N, UNVISITED);
		dfs(0, -1);
		printf("Case %d:\n", l);
		for(int i = 0; i < N; i++) dfs_num[i] == VISITED ? printf("Y ") : printf("N ");
		puts("");
		vi newList(dfs_num);
		for(int i = 1; i < N; i++){
			dfs_num.assign(N, UNVISITED);
			//if(newList[i] == VISITED){
				dfs(0, i);
				for(int j = 0; j < N; j++){
					if(newList[j] == UNVISITED || dfs_num[j] == VISITED){
						printf("N ");
					}else printf("Y ");
				}
				puts("");
			//}			
		}
		printf("\n\n");
	}
	return 0;
}

