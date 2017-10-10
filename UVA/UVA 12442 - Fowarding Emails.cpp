//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873

#include <iostream>
#include <cstdio>
#include <vector>

#define VISITED 1
#define UNVISITED -1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num;
vi pf_entrada;
int k = 0;

int dfs(int u){	
	int soma = 0;
	for(int j = 0; j < (int)AdjList[u].size(); j++){
		int v = AdjList[u][j];
		dfs_num[u] = VISITED;
		if(dfs_num[v] == UNVISITED){
			soma += 1 + dfs(v);
		}
		dfs_num[u] = UNVISITED;
	}
	return pf_entrada[u] = soma;
}

int main(int argc, char **argv)
{
	int T, V, c = 0;
	scanf("%d", &T);
	while(T--){
		k = 0;	
		int a, b;
		scanf("%d", &V);
		AdjList.assign(V, vi());
		dfs_num.assign(V, UNVISITED);
		pf_entrada.assign(V, -1);
		for(int i = 0; i < V; i++){
			scanf("%d %d", &a, &b);
			AdjList[a-1].push_back(b-1);
		}
		for(int i = 0; i < V; i++){
			if(pf_entrada[i] == -1) dfs(i);
		}
		int maior = -1;
		int pos = -1;
		for(int i = 0; i < V; i++){
		  if(pf_entrada[i] > maior){
		    maior = pf_entrada[i];
		    pos = i;
		  }
		}
		printf("Case %d: %d\n", ++c, pos+1);
	} 
	return 0;
}



