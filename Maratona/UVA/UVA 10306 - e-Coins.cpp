//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1247

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <math.h>
#include <stdlib.h>

#define INF 1000000000

using namespace std;

int memo[305][305];
int vetn[45], vets[45];
int x, n, S;


int main(int argc, char **argv)
{
	scanf("%d", &x);
	for(int q = 0; q < x; q++){
		int ans = INF;
		//memset(memo, -1, sizeof memo);
		for(int i = 0; i < 305; i++){
			for(int j = 0; j < 305; j++){
				memo[i][j] = INF;
			}
		}
			
		scanf("%d %d", &n, &S);
		for(int i = 0; i < n; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			vetn[i] = u; vets[i] = v;
		}
		
		memo[0][0] = 0;
		
		for(int k = 0; k < n; k++){
			for(int i = 0; i <= S; i++){
				for(int j = 0; j <= S; j++){
					if((i - vetn[k] >= 0) && (j - vets[k] >= 0)){
						memo[i][j] = min(memo[i][j], 1 + memo[i - vetn[k]][j - vets[k]]);
					}
				}
			}
		}
		
		for(int i = 0; i <= S; i++){
			for(int j = 0; j <= S; j++){
				if(i * i + j * j == S*S){
					ans = min(ans, memo[i][j]);
				}
			}
		}
		
		printf(ans == INF ? "not possible\n" : "%d\n", ans);
	}
	return 0;
}

