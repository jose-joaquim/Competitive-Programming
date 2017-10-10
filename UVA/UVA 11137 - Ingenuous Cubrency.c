//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2078

#include <stdio.h>

long long memo[10000 + 100];
int coins[21 + 10];

void dp(){
	int i, j;
	memo[0] = 1;
	for(i = 1; i <= 21; i++){
		for(j = i*i*i; j < 10001; j++){
			memo[j] += memo[j - i*i*i];
		}
	}
}

int main(int argc, char **argv)
{
	int ct, i;
	/*for(i = 1; i <= 21; i++){
		coins[i-1] = i*i*i;
	}*/
	dp();
	while(scanf("%d", &ct) != EOF){
		printf("%lld\n", memo[ct]);
	}
	return 0;
}

