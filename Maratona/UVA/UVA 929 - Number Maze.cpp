//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=870

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iiMatrix;

#define INF 1000000000

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int matrix[1001][1001];
int values[1001][1001];
int m, n;

bool valid(int r, int c){
	return (r < 0 || r >= m || c < 0 || c >= n);
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int l = 0; l < ct; l++){
		memset(matrix, 0, sizeof matrix);
		//memset(values, INF, sizeof values);
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j]);
				values[i][j] = INF;
			}
		}
		values[0][0] = matrix[0][0];
		priority_queue<iiMatrix, vector<iiMatrix>, greater<iiMatrix> > pq; 
		pq.push(iiMatrix(0, make_pair(0, 0)));
		while(!pq.empty()){
			iiMatrix front = pq.top(); pq.pop();
			int d = front.first; ii posAtual = front.second;
			if(d > values[posAtual.first][posAtual.second]) continue;
			for(int i = 0; i < 4; i++){
				int r = posAtual.first + dr[i];
				int c = posAtual.second + dc[i];
				if(!valid(r, c)){
					if(values[posAtual.first][posAtual.second] + matrix[r][c] < values[r][c]){//usar matrix[][] aqui no lugar de c
						
						values[r][c] = values[posAtual.first][posAtual.second] + matrix[r][c];
						pq.push(iiMatrix(values[r][c], make_pair(r, c)));
					}
				}
			}
		}
		printf("%d\n", values[m-1][n-1]);
	}
	return 0;
}

