#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000

int n, k;
vector<int> size;
vector<int> length;
int memo[1005][1005];
int used[101];

int solve(int id, int remW){
	if(id >= n)	return 0; 
	if(remW < 0) return -INF; 
	if(memo[id][remW] != -1) return memo[id][remW];
	if(size[id] > remW || used[id])	return memo[id][remW] = solve(id + 1, remW);
	//ignorando o item ou pegando o item
	int a = size[id] + solve(id + 1, remW - size[id]);
	int b = solve(id + 1, remW);
	//if(a >= b) used[id] = 1;
	return memo[id][remW] = max(a, b);
}

void print(int id, int remW){
	if(remW < 0 || id == n) return;
	//puts("oi");
	int a = solve(id+1, remW - size[id]);
	int b = memo[id][remW];
	printf("a eh %d e B EH %d\n", a, b);
	if(solve(id+1, remW - size[id]) == memo[id][remW]){
		//puts("oi");
		printf("%d%c", memo[id][remW], id == n-1 ? '\n' : '-');
		print(id + 1, remW - size[id]);
	}
}

int main(int argc, char **argv)
{
	memset(memo, -1, sizeof memo);
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int u;
		scanf("%d", &u);
		size.push_back(u);
	}
	for(int i = 0; i < k; i++){
		int u;
		scanf("%d", &u);
		length.push_back(u);
	}
	sort(length.begin(), length.end());
	int ans = -INF;
	do{
		memset(used, 0, sizeof used);
		int resp = 0;
		for(int i = 0; i < k; i++){
			resp += solve(0, length[i]);
			print(0, length[i]);
			//system("pause");
			//ver quais items foram usados
			/*itemsUsed();*/
			printf("RESP %d\n", resp);
			for(int k = 0; k < 70; k++){
				for(int j = 0; j < 30; j++){
					printf("%-2d ", memo[k][j]);
				}
				puts("");
			}
			system("pause");
		}
		//system("pause");
		//printf("resp eh %d\n", resp);
		ans = max(ans, resp);
	}while(next_permutation(length.begin(), length.end()));
	printf("%d\n", ans);
	return 0;
}

