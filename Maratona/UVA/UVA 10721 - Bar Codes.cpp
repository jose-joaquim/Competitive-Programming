//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1662

#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

unsigned long long memo[60][60][60];
int n1, k1, m1;

unsigned long long dp(int n, int k, int m){//max elements, number of groups, number of elements in a group
	if(memo[n][k][m] != (unsigned long long) -1) return memo[n][k][m];
	unsigned long long ans = 0;
	if(k == 0 && n == 0) return 1;
	if(k == 0 || n == 0) return 0;
	for(int i = 1; i <= m; i++){
		if(n - i >= 0) ans += dp(n - i, k - 1, m);
	}
	return memo[n][k][m] = ans;
}

int main(int argc, char **argv)
{
	while(scanf("%d %d %d", &n1, &k1, &m1) != EOF){
		memset(memo, -1, sizeof memo);
		printf("%llu\n", dp(n1, k1, m1));
	}
	return 0;
}

