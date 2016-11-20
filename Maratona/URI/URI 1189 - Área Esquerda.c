//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1189

#include <stdio.h>

int main(int argc, char **argv)
{
	char C;
	float matriz[12][12];
	float soma = 0, soma1 = 0, soma2 =0;
	int i, j;
	fgets(&C, 1, stdin);
	for(i = 0; i < 12; i++){
		for(j = 0; j < 12; j++){
			scanf("%f", &matriz[i][j]);
		}
	}
	for(j = 0; j < 5; j++){
		for(i = j+1; i < 6; i++){
			soma1 += matriz[i][j];
		}
		for(i = 10 - j; i > 5; i--){
			soma2 += matriz[i][j];
		}
		soma = soma1 + soma2;
	}
	switch(C){
		case 'S': printf("%.1f\n", soma); break;
		case 'M': printf("%.1f\n", soma/30); break;
	}
	return 0;
}

