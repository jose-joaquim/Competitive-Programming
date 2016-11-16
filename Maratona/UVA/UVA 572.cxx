#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

typedef vector<int> vi;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int matrix[101][101];
int visited[101][101];
int m, n;

void dfs(int u, int v){
	if(u < 0 || u >= m || v < 0 || v >= n || visited[u][v]) return;
	visited[u][v] = 1;
	if(matrix[u][v] != 1) return;
	for(int d = 0; d < 8; d++){
		dfs(u + dr[d], v + dc[d]);
	}
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &m, &n) && m){
		char c;
		int ans = 0;
		memset(visited, 0, sizeof visited);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> c;
				if(c == '@') matrix[i][j] = 1; else matrix[i][j] = 0;
			}
		}
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(!visited[i][j] && matrix[i][j] == 1){
					ans++;
					dfs(i, j);
				}
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}

