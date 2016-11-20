//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=762

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

#define INF 1000000000

int main(int argc, char **argv)
{
	int a, b, numcase = 0;
	while(scanf("%d %d", &a, &b) && (a || b)){
		int AdjMatrix[102][102];
		
		for(int i = 0; i < 102; i++)
			for(int j = 0; j < 102; j++)
				AdjMatrix[i][j] = INF;
				
		AdjMatrix[a][b] = 1;
		
		int u, v;
		while(scanf("%d %d", &u, &v) && (u || v)){
			AdjMatrix[u][v] = 1;
		}
		
		for(int i = 0; i < 102; i++) AdjMatrix[i][i] = 0;
		
		for(int k = 0; k < 102; k++)
			for(int i = 0; i < 102; i++)
				for(int j = 0; j < 102; j++)
					AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);
					
		double soma = 0.0;
		int clicks = 0;
		for(int i = 1; i < 102; i++){
			for(int j = 1; j < 102; j++){
				if(AdjMatrix[i][j] != INF && !(i == j)){
					soma += (double) AdjMatrix[i][j]; 
					clicks++;
				}				
			}
		}
		printf("Case %d: average length between pages = %.3lf clicks\n", ++numcase, soma/(double)clicks);
	}
	return 0;
}

