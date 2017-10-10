#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int memo[505][505];
vector<int> depth;
vector<int> amount;
int cap, w;

int val(int id, int remW){
	if(id == (int) depth.size() || remW == 0) return 0;
	if(memo[id][remW] != -1) return memo[id][remW];
	
	if(depth[id] > remW) return memo[id][remW] = val(id + 1, remW); 
	
	return memo[id][remW] = max(val(id + 1, remW), amount[id] + val(id + 1, remW - depth[id]));
}
int main(int argc, char **argv)
{
	cin >> cap >> w;
	int x, k, q;
	cin >> x;
	for(int i = 0; i < x; i++){
		cin >> k >> q;
		depth.push_back(k);
		depth.push_back(q);
	}
	memset(memo, -1, sizeof memo);
	printf("%d\n", val(0, 210));
	return 0;
}

