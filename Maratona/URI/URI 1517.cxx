#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int n, m, k, sz;
int startx, starty;
int memo[22][22][2005];
int grid[22][22][2005];

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(int x, int y, int tempo){
	if(x <= 0 || x > n || y <= 0 || y > m) return 0;
	
	if(tempo == sz + 1) return 0;

	if(memo[x][y][tempo] != -1){
		return memo[x][y][tempo];
	}
	
	int c1 = 0;
	if(grid[x][y][tempo] == 1){
		for(int i = 0; i < 8; i++){
			c1 = max(c1, 1 + max(solve(x + dr[i], y + dc[i], tempo + 1), solve(x, y, tempo + 1)));
		}
	}else{
		for(int i = 0; i < 8; i++){
			c1 = max(c1, max(solve(x + dr[i], y + dc[i], tempo + 1), solve(x, y, tempo + 1)));
		}
	}
	return memo[x][y][tempo] = c1;
}


int main(int argc, char **argv)
{
	while(scanf("%d %d %d", &n, &m, &k) && (n || m || k)){
		sz = -1;
		memset(memo, -1, sizeof memo);
		memset(grid, 0, sizeof memo);
		for(int i = 0; i < k; i++){
			int u, v, w;
			cin >> u >> v >> w;
			sz = max(sz, w);
			grid[u][v][w] = 1;
		}
		cin >> startx >> starty;
		printf("%d\n", solve(startx, starty, 0));
	}
	return 0;
}
