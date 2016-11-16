#include <bits/stdc++.h>

using namespace std;

int R, C;
int grid[105][105];
int visited[105][105];
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool outGrid(int a, int b){
	return (a < 0 || a >= R || b < 0 || b >= C);
}

int floodfill(int x, int y, int lastHeigth){
	if(outGrid(x, y)) return 0;
	if(grid[x][y] == lastHeigth) return 0;
	
	return 0;
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &R, &C) != EOF){
		memset(visited, 0, sizeof visited);
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				scanf("%d", &grid[i][j]);
			}
		}
	}
	return 0;
}

