#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <string.h>
#include <stdlib.h>


#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int, pair<int, int> > iiMatrix;

int m, n;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int matrix[501][501];
int values[501][501];

bool valid(int r, int c){
	return (r < 0 || r >= m || c < 0 || c >= n) && (matrix[r][c] != INF);
}

int main(int argc, char **argv)
{
	int rowIni, colIni, rowFim, colFim;
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			char c;
			values[i][j] = INF;
			cin >> c;
			if(c == 'H' || c == 'E' || c == '.'){
				matrix[i][j] = 0;
			}else if(c == '#'){
				matrix[i][j] = INF;
			}else{
				matrix[i][j] = atoi(&c);
			}
			if(c == 'H'){
				rowIni = i;
				colIni = j;
			}
			if(c == 'E'){
				rowFim = i;
				colFim = j;
			}
		}
	}
	values[rowIni][colIni] = 0;
	priority_queue<iiMatrix, vector<iiMatrix>, greater<iiMatrix> > pq;
	pq.push(iiMatrix(0, ii(rowIni, colIni)));
	while(!pq.empty()){
		iiMatrix front = pq.top(); pq.pop();
		int d = front.first; ii u = front.second;
		if(d > values[u.first][u.second]) continue;
		for(int i = 0; i < 4; i++){
			int r = u.first + dr[i];
			int c = u.second + dc[i];
			if(!valid(r, c)){
				if(values[u.first][u.second] + matrix[r][c] < values[r][c]){
					values[r][c] = values[u.first][u.second] + matrix[r][c];
					pq.push(iiMatrix(values[r][c], ii(r, c)));
				}
			}
		}
	}
	values[rowFim][colFim] == INF ? printf("ARTSKJID\n") : printf("%d\n", values[rowFim][colFim]);
	return 0;
}

