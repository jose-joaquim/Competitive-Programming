//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1286

#include <stdio.h>
#include <string.h>

#define INF 1000000000
#define max(a, b) ((a > b) ? a : b)

int N;
int sizeBag;
int time[31];
int pizzas[31];
int memo[350][350];

int val(int id, int remT){
	if(remT > sizeBag) return -INF;
	if(id == N) return 0;
	if(memo[id][remT] != -1) return memo[id][remT];
	if(remT + pizzas[id] > sizeBag) return memo[id][remT] = val(id + 1, remT);
	return memo[id][remT] = max(val(id + 1, remT), time[id] + val(id + 1, remT + pizzas[id]));
}
int main(int argc, char **argv)
{
	while(scanf("%d", &N) && N){
		memset(memo, -1, sizeof memo);
		int i;
		scanf("%d", &sizeBag);
		for(i = 0; i < N; i++){
			scanf("%d %d", &time[i], &pizzas[i]); 
		}
		printf("%d min.\n", val(0, 0));
	}
	return 0;
}

