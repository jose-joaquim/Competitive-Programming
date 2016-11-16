#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

#define INF 1000000000

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int R, C;
int rowIni, colIni, rowFim, colFim;
int matrix[1001][1001];
int visited[1001][1001];
int nivel[1001][1001];

bool valid(int r, int c){
	return (r < 0 || r >= R || c < 0 || c >= C);
}

int main(int argc, char **argv)
{
	int c;
	while(scanf("%d %d", &R, &C) && (R || C)){
		scanf("%d", &c);
		memset(matrix, 0, sizeof matrix);
		memset(visited, 0, sizeof visited);
		memset(nivel, 0, sizeof nivel);
		for(int i = 0; i < c; i++){
			int rowNumber, qtd;
			cin >> rowNumber >> qtd;
			for(int j = 0; j < qtd; j++){
				int k;
				scanf("%d", &k);
				matrix[rowNumber][k] = 1;
			}
		}
		scanf("%d %d %d %d", &rowIni, &colIni, &rowFim, &colFim);
		queue<pair<int, int> > q;
		nivel[rowIni][colIni] = 0;
		q.push(make_pair(rowIni, colIni));
		visited[rowIni][colIni] = 1;
		while(!q.empty()){
			pair<int, int> u = q.front(); q.pop();
			for(int i = 0; i < 4; i++){
				int r = u.first + dr[i];
				int c = u.second + dc[i];
				if(!valid(r, c) && !visited[r][c] && !matrix[r][c]){
					visited[r][c] = 1;
					nivel[r][c] = nivel[u.first][u.second] + 1;
					q.push(make_pair(r, c));
				}
			}
		}
		printf("%d\n", nivel[rowFim][colFim]);
	}
	return 0;
}

