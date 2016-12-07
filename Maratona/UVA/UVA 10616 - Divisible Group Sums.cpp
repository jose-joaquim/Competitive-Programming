//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1557

#include <iostream>
#include <cstdio>
#include <string.h>

#define INF 1000000000;

using namespace std;

long long memo[205][205][20];
long long items[250];
int n, d, m, q;

long long solve(int id, int remW, int sum){
	if(remW <= 0){
		if(sum == 0){
			return 1;
		}else return 0;
	}
	if(id == n) return 0;
	if(memo[id][remW][sum] != -1) return memo[id][remW][sum];
	return memo[id][remW][sum] = solve(id + 1, remW, sum%d) + solve(id+1, remW - 1, ((sum + items[id])%d+d)%d);
}

int main(int argc, char **argv)
{
	int cs = 0;
	while(scanf("%d %d", &n, &q) && (n || q)){
		for(int i = 0; i < n; i++){
			scanf("%lld", &items[i]);
		}
		printf("SET %d:\n", ++cs);
		for(int i = 1; i <= q; i++){
			memset(memo, -1, sizeof memo);
			scanf("%d %d", &d, &m);
			printf("QUERY %d: %lld\n", i, solve(0, m, 0));
		}
	}
	return 0;
}

