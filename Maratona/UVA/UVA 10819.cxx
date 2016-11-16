#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int memo[110][10000];
vector<int> price;
vector<int> W;
int m, n;

int val(int id, int remW){
	if(remW > m && m < 1800)
		return -1000000000;
	
	if(remW > m + 200)
		return -1000000000;
	if(id == n){
		if(remW > m && remW <= 2000){
			return -1000000000;
		}else{
			return 0;
		}
	}
	if(memo[id][remW] != -1) return memo[id][remW];
	
	return memo[id][remW] = max(val(id + 1, remW), W[id] + val(id + 1, remW + price[id]));
}

int main(int argc, char **argv)
{
	
	while(scanf("%d %d", &m, &n) != EOF){
		memset(memo, -1, sizeof memo);
		price.resize(m);
		W.resize(n);
		for(int i = 0; i < n; i++){
			scanf("%d %d", &price[i], &W[i]);
		}
		printf("%d\n", val(0, 0));
	}
	return 0;
}

