#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

#define INF 1000000000

int dp[1005][6005];
int weight[1005], capacity[1005];
int W, maxL;
int ct;

int rc(int L, int remW){	
	if(remW < 0) return -INF;
	if(L == ct) return 0;
	
	if(dp[L][remW] != -1) return dp[L][remW];
	
	if(remW < weight[L]) return dp[L][remW] = rc(L + 1, remW);
	
	return dp[L][remW] = max(rc(L + 1, remW), 1 + rc(L + 1, min(remW - weight[L], capacity[L])));
}

int main(int argc, char **argv)
{
	while(scanf("%d", &ct) && ct){
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < ct; i++){
			scanf("%d %d", &weight[i], &capacity[i]);
		}
		printf("%d\n", rc(0, 6002));
	}
	return 0;
}

