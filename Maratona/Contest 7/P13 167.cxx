#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 8

using namespace std;

int row[8], TC, a, b, count, soma = 0, somaFinal = 0;
int matriz[N][N];

bool place(int r, int c){
	for(int prev = 0; prev < c; prev++)
		if(row[prev] == r || (abs(row[prev] - r) == abs(prev - c))){
			return false;
		}		
	return true;
}

void backtrack(int c){
	if(c == 8 && row[b] == a){
		soma = 0;
		/*printf("%2d     %d", ++count, row[0]);
		for(int j = 1; j < 8; j++) printf(" %d", row[j]);
		printf("\n");*/
		
		//for(int j = 0; j < 8; j++) printf(" linha %d coluna %d\n", row[j], j);
		for(int i = 0; i < 8; i++){
			soma += matriz[7-row[i]][i];
			if(soma >= somaFinal){
				somaFinal = soma;
			}
		}
		//printf("%d %d\n", somaFinal, soma);
	}
	for(int r = 0; r < 8; r++){
		if(place(r, c)){
			row[c] = r; 
			backtrack(c + 1);
		}		
	}	
}

int main(int argc, char **argv)
{
	scanf("%d", &TC);
	while(TC--){
		somaFinal = 0;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				scanf("%d", &matriz[i][j]);
			}
		}
		for(int i = 0; i < 8; i++){
			a = i; b = 0;
			memset(row, 0, sizeof row);
			count = 0;
			backtrack(0);
		}
		printf("%5d\n", somaFinal);
	}
	return 0;
}

