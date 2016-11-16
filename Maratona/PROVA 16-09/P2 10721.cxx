#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>

using namespace std;

int n, k, m;
int memo[55][55][55];

int solve(int n1, int k2, int m3){
	if(n1 == 0 && k2 != 0){
		return 0;
	}
	if(k2 == 0 && m3 == 0){
		return 1;
	}
	
	if(memo[n1][k2][m3] != -1) return memo[n1][k2][m3];
	
	int ans = 0;
	
	if(m3 == 0){
		memo[n1][k2][m3] = solve(n1-1, k2-1, m);
	}else{
		memo[n1][k2][m3] = solve(n1-1, k2, m3-1);
	}
	
	return memo[n1][k2][m3] = ans;
}

int main(int argc, char **argv)
{
	while(scanf("%d %d %d", &n, &k, &m) != EOF){
		memset(memo, -1, sizeof memo);
		printf("%d\n", solve(n, k, m));
	}
	return 0;
}
