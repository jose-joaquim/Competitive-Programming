//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1081


#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> dfs_num;
int AdjList[25][25];
int V, E;

bool dfs(int u, int depth){
	bool go = false;
    dfs_num[u] = 1;
    for(int q = 0; q < V; q++){
		if(AdjList[u][q]){
			go = true;
			if(dfs_num[q] == -1){
				cout << string(depth, ' ');
				printf("%d-%d pathR(G,%d)\n", u, q, q);
				dfs(q, depth + 2);
			}else{
				cout << string(depth, ' ');
				printf("%d-%d\n", u, q);
			}
		}
	}
	return go;
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	for(int qq = 1; qq <= n; qq++){
		memset(AdjList, 0, sizeof AdjList);
		scanf("%d %d", &V, &E);
		dfs_num.assign(V, -1);
		for(int i = 0; i < E; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[u][v] = 1;
		}
		printf("Caso %d:\n", qq);
		for(int i = 0; i < V; i++){
			if(dfs_num[i] == -1){
				if(dfs(i, 2)) puts("");
			}
		}
	}
	return 0;
}

