#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;

int n, an1;
long long memo[25][505];

long long dp(int i, int j){
	if(memo[i][j] != -1){
		return memo[i][j];
	}
	if(i >= j){
		long long aux1 = 0, aux2 = 0;
		if(i < n){
			for(int k = i + 1; k <= n; k++){
				aux1 = max(aux1, dp(k, 1) + dp(k, j));
			}				
		}else if(i == n){
			aux1 = 0;
		}
		
		if(j > 0){
			for(int k = 1; k < j; k++){
				aux2 = max(aux2, dp(i, k) + dp(n, k));
			}			
		}else if(j == 0) aux2 = 0;
		
		return memo[i][j] = aux1 + aux2;
	}
	
	if(i < j){
		long long aux1 = 0;
		for(int k = i; k < j; k++){
			aux1 = max(aux1, dp(i, k) + dp(k+1, j));
		}	
		return memo[i][j] = aux1;
	}
	
	return memo[i][j];
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &n, &an1) != EOF){
		memset(memo, -1, sizeof memo);
		memo[n][1] = an1;
		printf("%lld\n", dp(1, n));
	}
	return 0;
}



