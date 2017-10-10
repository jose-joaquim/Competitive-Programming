//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1216
#include <stdio.h>

int main(int argc, char **argv)
{
	double dist;
	int q = 0, qtd = 0;
	char nome[50];
	while(gets(nome)){
		scanf("%d", &q);
		getchar();
		dist += q;
		qtd++;
	}
	printf("%.1f\n", dist/qtd);
	return 0;
}

