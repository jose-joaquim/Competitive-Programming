//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1288

#include <stdio.h>
#include <string.h>

#define INF 1000000000
#define max(a, b) ((a > b) ? a : b)

int N;
int sz_projeteis[55];
int power_dest[55];
int size_canhao;
int resistencia;
int memo[105][105];

int val(int id, int remR){
	if(remR < 0) return -INF;
	if(id == N) return 0;
	if(memo[id][remR] != -1) return memo[id][remR];
	if(sz_projeteis[id] > remR) return memo[id][remR] = val(id + 1, remR);
	return memo[id][remR] = max(val(id + 1, remR), power_dest[id] + val(id + 1, remR - sz_projeteis[id]));
}

int main(int argc, char **argv)
{
	int ct, k, i;
	scanf("%d", &ct);
	for(k = 1; k <= ct; k++){
		memset(memo, -1, sizeof memo);
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d %d", &power_dest[i], &sz_projeteis[i]);			
		}
		scanf("%d", &size_canhao);
		scanf("%d", &resistencia);
		int ans = val(0, size_canhao);
		puts((ans >= resistencia) ? "Missao completada com sucesso" : "Falha na missao");
	}
	return 0;
}

