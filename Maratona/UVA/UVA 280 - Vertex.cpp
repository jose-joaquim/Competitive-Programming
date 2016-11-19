//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=216

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define VISITED 1
#define UNVISITED -1
#define INF 1000000000

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num;
vi unvi;
int vet[101];

int nSearch;

void dfs(int u){
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int) AdjList[u].size(); i++){
		int v = AdjList[u][i];
		vet[v] = 1;
 		if(dfs_num[v] == UNVISITED){
			dfs(v);
		}
	}
}

int main(int argc, char **argv)
{
	int V;
	while(scanf("%d", &V) && V){
		AdjList.assign(V+1, vi());
		int v_pos, p, count = 0;
		while(scanf("%d", &v_pos) && v_pos != 0){
			while(scanf("%d", &p) && p != 0){
				AdjList[v_pos-1].push_back(p-1);
			}
		}
		scanf("%d", &nSearch);
		int a;
		for(int i = 0; i < nSearch; i++){
			fill(vet,vet+V,0);
			scanf("%d", &a);
			dfs_num.assign(V, UNVISITED);
			unvi.clear();
			count = 0;
			dfs(a-1);
			for(int j = 0; j < V; j++){
				if(!vet[j]){
					count++;
					unvi.push_back(j+1);
				}
			}
				printf("%d", count);
				for(int i = 0; i < count; i++) printf(" %d", unvi[i]);
				printf("\n");
		}
	}
	return 0;
}

