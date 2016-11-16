#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <string.h>

using namespace std;

#define INF 1000000000

int m, n;
int memo[1005][1005];
int W[21];

int dp(int id, int remW){
	if(id == n) return 0;
	if(remW < 0) return -INF;
	if(memo[id][remW] != -1) return memo[id][remW];
	if(W[id] > remW) return memo[id][remW] = dp(id + 1, remW);
	return memo[id][remW] = max(dp(id + 1, remW), W[id] + dp(id + 1, remW - W[id]));
}

int main(int argc, char **argv)
{
	scanf("%d", &m);
	for(int q = 0; q < m; q++){
		vector<int> W;
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		int ans = -1;
		stringstream ss;
		string linha, palavra;
		ss << linha;
		while(ss >> palavra){
			W.push_back(stoi(palavra, nullptr));
		}
		printf("%d\n", dp(0, ans));
		for(int i = 0; i < 35; i++){
			for(int j = 0; j < 35; j++){
				printf("%2d ", memo[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
