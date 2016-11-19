//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int matrix[101][101];
int visited[101][101];
int N;

void dfs(int u, int v){
	if(u < 0 || u >= N || v < 0 || v >= N || visited[u][v]) return;
	visited[u][v] = 1;
	if(matrix[u][v] != 1) return;
	for(int d = 0; d < 8; d++){
		dfs(u + dr[d], v + dc[d]);
	}
}

int main(int argc, char **argv)
{
	int caso = 0;
	while(scanf("%d", &N) != EOF){
		int ans = 0;
		char c;
		memset(visited, 0, sizeof visited);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> c;
				if(c == '1') matrix[i][j] = 1; else matrix[i][j] = 0;
				//scanf("%d", &matrix[i][j]);
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(matrix[i][j] == 1 && !visited[i][j]){
					ans++;
					dfs(i, j);
				}
			}
		}
		
		printf("Image number %d contains %d war eagles.\n", ++caso, ans);
		
	}
	return 0;
}

