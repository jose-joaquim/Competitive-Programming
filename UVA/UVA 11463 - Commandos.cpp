//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2458

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

#define INF 1000000000

int AdjMat[105][105];

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int l = 1; l <= ct; l++){
		//memset(AdjMat, INF, sizeof AdjMat);
		int s, d, n, r;
		scanf("%d %d", &n, &r);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				AdjMat[i][j] = INF;
			}
		}
		for(int i = 0; i < n; i++){
			AdjMat[i][i] = 0;
		}
		for(int i = 0; i < r; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			AdjMat[u][v] = 1;
			AdjMat[v][u] = 1;
		}
		scanf("%d %d", &s, &d);
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
					
		int time = 0;
					
		for(int i = 0; i < n; i++){
			if(AdjMat[s][i] != INF && AdjMat[i][d] != INF){
				time = max(time, AdjMat[s][i] + AdjMat[i][d]);
			}
		}
					
		printf("Case %d: %d\n", l, time);
	}
	return 0;
}

