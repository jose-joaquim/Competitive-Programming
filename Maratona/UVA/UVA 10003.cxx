#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

#define INF 1000000000

int memo[55][55];
int A[55];
int n;

int dp(int left, int right){
	if(memo[left][right] != -1) return memo[left][right];
	if(left + 1 == right) return memo[left][right] = 0;
	
	int ans = INF;
	for(int i = left+1; i < right; i++){
		ans = min(ans, dp(left, i) + dp(i, right) + (A[right] - A[left]));
	}
	
	return memo[left][right] = ans;
}

int main(int argc, char **argv)
{
	while(scanf("%d", &n) && n){
		memset(memo, -1, sizeof memo);
		int l;
		scanf("%d", &l);
		for(int i = 1; i <= l; i++) cin >> A[i];
		A[0] = 0; A[l+1] = n;
		
		printf("The minimum cutting is %d.\n", dp(0, l+1));
	}
	return 0;
}

