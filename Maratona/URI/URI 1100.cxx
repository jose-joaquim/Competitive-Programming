#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef pair<int, int> ii;

int xadrez[10][10];
int fromX, fromY, toX, toY;

bool valid(ii x){
	return (x.first > 0 && x.first < 9  && x.second > 0 && x.second < 9);
}

int BFS(){
	memset(xadrez, -1, sizeof xadrez);
	queue<ii> q;
	q.push(ii(fromX, fromY));
	xadrez[fromX][fromY] = 0;
	while(!q.empty()){
		ii u = q.front(); q.pop();
		
		if(u.first == toX && u.second == toY) break;
		
		ii v1 = u;		
		v1.first += 2; v1.second += 1;
		if(valid(v1) && xadrez[v1.first][v1.second] == -1){
			q.push(v1);
			xadrez[v1.first][v1.second] = xadrez[u.first][u.second] + 1;
		}
		
		v1 = u;
		v1.first += 2; v1.second -= 1;
		if(valid(v1) && xadrez[v1.first][v1.second] == -1){
			q.push(v1);
			xadrez[v1.first][v1.second] = xadrez[u.first][u.second] + 1;
		}
		
		v1 = u;
		v1.first -= 2; v1.second -= 1;
		if(valid(v1) && xadrez[v1.first][v1.second] == -1){
			q.push(v1);
			xadrez[v1.first][v1.second] = xadrez[u.first][u.second] + 1;
		}
		
		v1 = u;
		v1.first -= 2; v1.second += 1;
		if(valid(v1) && xadrez[v1.first][v1.second] == -1){
			q.push(v1);
			xadrez[v1.first][v1.second] = xadrez[u.first][u.second] + 1;
		}
		
		v1 = u;
		v1.first += 1; v1.second += 2;
		if(valid(v1) && xadrez[v1.first][v1.second] == -1){
			q.push(v1);
			xadrez[v1.first][v1.second] = xadrez[u.first][u.second] + 1;
		}
		
		v1 = u;
		v1.first -= 1; v1.second += 2;
		if(valid(v1) && xadrez[v1.first][v1.second] == -1){
			q.push(v1);
			xadrez[v1.first][v1.second] = xadrez[u.first][u.second] + 1;
		}
		
		v1 = u;
		v1.first += 1; v1.second -= 2;
		if(valid(v1) && xadrez[v1.first][v1.second] == -1){
			q.push(v1);
			xadrez[v1.first][v1.second] = xadrez[u.first][u.second] + 1;
		}
		
		v1 = u;
		v1.first -= 1; v1.second -= 2;
		if(valid(v1) && xadrez[v1.first][v1.second] == -1){
			q.push(v1);
			xadrez[v1.first][v1.second] = xadrez[u.first][u.second] + 1;
		}
		
	}
	
	return xadrez[toX][toY];
}

int main(int argc, char **argv)
{
	char ini[3], fim[3];
	while(scanf("%s %s", ini, fim) != EOF){
		//printf("LI %s E %s\n", ini, fim);
		fromX = (ini[0] - 97)+1;
		fromY = atoi(&ini[1]);
		toX = (fim[0] - 97)+1;
		toY = atoi(&fim[1]);
		printf("To get from %s to %s takes %d knight moves.\n", ini, fim, BFS());
	}
	return 0;
}

