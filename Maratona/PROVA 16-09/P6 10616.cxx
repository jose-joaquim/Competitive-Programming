#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int memo[210][210][210];
int vet[205];
int n, q, d, qtd;

int solve(int x, int q, int sum){
	if(x > n) return 0;
	if(q == 0){
		if(sum == 0){
			//puts("oi");
			return 1;
		}else{
			//puts("Q");
			return 0;
		}
	}
	
	if(memo[x][q][sum] != -1) return memo[x][q][sum];
	
	return memo[x][q][sum] = solve(x + 1, q, sum%d) + solve(x + 1, q - 1, (sum + vet[x])%d);
}

int main(int argc, char **argv)
{
	int cs = 0;
	while(scanf("%d %d", &n, &q) && (n || q)){
		for(int i = 0; i < n; i++){
			scanf("%d", &vet[i]);			
		}
		printf("SET %d:\n", ++cs);
		for(int x = 0; x < q; x++){
			memset(memo, -1, sizeof memo);
			scanf("%d %d", &d, &qtd);
			printf("QUERY %d: %d\n", x + 1, solve(0, qtd, 0));
		}
	}
	return 0;
}

