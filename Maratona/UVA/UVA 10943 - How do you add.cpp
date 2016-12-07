//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1884

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int n,k;
int memo[102][102];

int solve(int q, int K){
	if(K == 1) return 1;
	
	if(memo[q][K] != -1) return memo[q][K];
	
	int ans = 0;
	
	for(int i = 0; i <= q; i++){
		ans += solve(q - i, K - 1);
	}
	return memo[q][K] = ans % 1000000;
}
int main(int argc, char **argv)
{
	while(scanf("%d %d", &n, &k) && (n || k)){
		memset(memo, -1, sizeof memo);
		printf("%d\n", solve(n, k)%1000000);
	}
	return 0;
}

