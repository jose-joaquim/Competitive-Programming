//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1487

#include <stdio.h>
#include <string.h>

#define max(a, b) ((a > b) ? a : b)
#define INF 1000000000;

int n, t;
int memo[105][605];
int D[605], P[105];
int maxBrinks;

int val(int id, int remW){
	//printf("remW aqui eh %d\n", remW);
	if(remW < 0) return -INF;
	if(id == n) return 0;
	if(memo[id][remW] != -1) return memo[id][remW];
	if(D[id] > remW) return memo[id][remW] = val(id + 1, remW);
	return memo[id][remW] = max(val(id + 1, remW), P[id] + val(id, remW - D[id]));
}

int main(int argc, char **argv)
{
	int turn = 0;
	while(scanf("%d %d", &n, &t) && (n || t)){
		memset(memo, -1, sizeof memo);
		int i;
		for(i = 0; i < n; i++){
			scanf("%d %d", &D[i], &P[i]);
		}		
		printf("Instancia %d\n", ++turn);
		printf("%d\n", val(0, t));
		puts("");
	}
	return 0;
}

