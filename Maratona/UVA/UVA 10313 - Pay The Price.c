//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1254

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long memo[305][1001 + 100];
int keys[4];

void dp(){
	int i, j, k;
	
	for(i = 0; i < 1002; i++) memo[0][i] = 1;
	
	for(k = 1; k < 1002; k++)
		for(i = 1; i <= k; i++){
			for(j = i; j < 301; j++){
				memo[j][k] += memo[j - i][k];
			}
		}
}

int main(int argc, char **argv)
{
	dp();
	char ct[10];
	while(gets(ct)){
		int k = 0;
		fflush(stdin);
		char *part = strtok (ct, " ");
		while(part != NULL){
			keys[k++] = atoi(part);
			part = strtok (NULL, " ");
		}
		switch(k){
			case 1:
				printf("%lld\n", memo[keys[0]][300]); break;
			case 2:
				printf("%lld\n", memo[keys[0]][keys[1]]); break;
			case 3:
				printf("%lld\n", memo[keys[0]][keys[2]] - memo[keys[0]][keys[1]-1]); break;
		}
	}
	return 0;
}

