#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	int m, n;
	cin >> n >> m;
	int matrix[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	int total = 0;
	for(int i = 0; i < n; i++){
		int fez = 1;
		for(int j = 0; j < m; j++){
			fez = fez && matrix[i][j];
		}
		if(fez){
			//printf("jogador %d fez gol em todas as partidas\n", i);
			total++;
		}
	}
	printf("%d\n", total);
	return 0;
}

