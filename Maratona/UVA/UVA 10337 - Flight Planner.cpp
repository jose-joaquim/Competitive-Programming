//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1278

#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

#define CLIMB 60
#define HOLD 30
#define SINKING 20
#define INF 1000000000

using namespace std;

int X, miles;
int grid[11][1005];
int memo[75][1005];

int solve(int x, int y){
	if(x > 9 || x < 0 || y > miles || y < 0) return INF; //sai do grid
	
	if(x == 9 && y == miles) return 0; //cheguei no destino
	
	if(memo[x][y] != -1) return memo[x][y];//ja passei por aqui
	
	//levantar voo
	int c1 = CLIMB + (-grid[x][y]) + solve(x - 1, y + 1);
	//ficar na mesma linha
	int c2 = HOLD + (-grid[x][y]) + solve(x, y + 1);
	//ir pra baixo
	int c3 = SINKING + (-grid[x][y]) + solve(x + 1, y + 1);
	
	int ans = INF;
	ans = min(ans, min(c1, c2));
	ans = min(ans, c3);
	return memo[x][y] = ans;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int q = 0; q < ct; q++){
		memset(memo, -1, sizeof memo);
		scanf("%d", &X);
		miles = X/100;
		for(int i = 0; i <= 9; i++){
			for(int j = 0; j < miles; j++){
				scanf("%d", &grid[i][j]);
			}
		}
		/*printf("\n\n");
		for(int i = 0; i <= 9; i++){
			for(int j = 0; j < miles; j++){
				printf("%d ", grid[i][j]);
			}
			puts("");
		}*/
		printf("%d\n", solve(9, 0));
		if(q < ct) printf("\n");
	}
	return 0;
}

