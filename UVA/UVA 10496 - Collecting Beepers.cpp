//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1437
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

#define INF 1000000000

using namespace std;

int grid[25][25];
int memo[15][1 << 15];
int n, m, x, citys;
int ini, fim;

int dist(int x1, int y1, int x2, int y2){
	return fabs(x1 - x2) + fabs(y1 - y2);
	//fabs((x1 - x2) + (y1 - y2));
}

int tsp(int pos, int mask){
	if((1 << citys) - 1 == mask){
		return grid[pos][0];
	}
	if(memo[pos][mask] != -1) return memo[pos][mask];
	int ans = INF;
	for(int nxt = 0; nxt < citys; nxt++){
		if(nxt != pos && !(mask & (1 << nxt))){
			ans = min(ans, grid[pos][nxt] + tsp(nxt, mask | (1 << nxt)));
		}
	}
	return memo[pos][mask] = ans;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int q = 0; q < ct; q++){
		scanf("%d %d", &n, &m);
		scanf("%d %d", &ini, &fim);
		scanf("%d", &x);
		int vet[x+2][x+2];
		citys = 1 + x;
		memset(memo, -1, sizeof memo);
		//printf("1 << citys - 1 eh %d\n", (1 << citys) - 1);
		/*for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				grid[i-1][j-1] = fabs(i - j);
			}
		}*/
		vet[0][0] = ini; vet[0][1] = fim;
		for(int i = 1; i <= x; i++){
			scanf("%d %d", &vet[i][0], &vet[i][1]);
		}
		for(int i = 0; i <= x; i++){
			for(int j = 0; j <= x; j++){
				int val = dist(vet[i][0], vet[i][1], vet[j][0], vet[j][1]);
				//printf("dist mahattan de (%d, %d) para (%d, %d) eh %d\n", vet[i][0], vet[i][1], vet[j][0], vet[j][1], val);
				grid[i][j] = val;
				//grid[i][j] = dist(
			}
			//puts("");
		}
		/*
		for(int i = 0; i <= x; i++){
			for(int j = 0; j <= x; j++){
				printf("%2d ", grid[i][j]);
			}
			puts("");
		}*/
		printf("The shortest path has length %d\n", tsp(0, 1));
	}
	return 0;
}

