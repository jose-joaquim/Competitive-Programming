//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2445


#include <stdio.h>
#include <string.h>

#define INF 1000000000
#define max(a, b) ((a > b) ? a : b)

int M, C;
int price[25][25];
int memo[210][25];

int solve(int money, int c){
	int j;
	if(money < 0) return -INF;
	if(c == C) return M - money;
	
	if(memo[money][c] != -1){
		 return memo[money][c];
	 }
	
	int ans = -1;
	
	for(j = 1; j <= price[c][0]; j++){
		ans = max(ans, solve(money - price[c][j], c + 1));
	}
	
	return memo[money][c] = ans;
}

int main(int argc, char **argv)
{
	int ct, i, j;
	scanf("%d", &ct);
	while(ct--){
		memset(memo, -1, sizeof memo);
		scanf("%d %d", &M, &C);
		for(i = 0; i < C; i++){
			scanf("%d", &price[i][0]);
			for(j = 1; j <= price[i][0]; j++){
				scanf("%d", &price[i][j]);
			}
		}
		int resp = solve(M, 0);
		printf(resp < 0 ? "no solution\n" : "%d\n", resp);
	}
	return 0;
}

