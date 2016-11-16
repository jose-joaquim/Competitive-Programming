#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool valid(int r, int c){
	return (r < 0 || r >= 5 || c < 0 || c >= 5);
}

int main(int argc, char **argv)
{
	int ct;
	cin >> ct;
	for(int l = 0; l < ct; l++){
		int matrix[5][5];
		int visited[5][5];
		memset(matrix, 0, sizeof matrix);
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				cin >> matrix[i][j];
				if(matrix[i][j] == 1){
					visited[i][j] = 1;
				}else visited[i][j] = 0;
			}
		}
		queue<ii> q; q.push(ii(0, 0));
		visited[0][0] = 1;
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int u = front.first, v = front.second;
			for(int d = 0; d < 4; d++){
				int r = u + dr[d];
				int c = v + dc[d];
				if(!valid(r, c) && !visited[r][c] && !matrix[r][c]){
					visited[r][c] = 1;
					q.push(ii(r, c));
				}
			}
		}
		puts(visited[4][4] ? "COPS" : "ROBBERS");
	}
	return 0;
}

