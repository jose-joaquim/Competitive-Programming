//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1171

#include <stdio.h>
#include <stdlib.h>

int comp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char **argv)
{
	int qtd, i, contador = 0;;
	scanf("%d", &qtd);
	int vetor[qtd];
	for(i = 0; i < qtd; i++){
		scanf("%d", &vetor[i]);
	}
	qsort(&vetor, qtd, sizeof(int), comp);
	for(i = 0; i < qtd; i++){
		if(vetor[i] == vetor[i+1]){
			contador++;
		}else{
			printf("%d aparece %d vez(es)\n", vetor[i], contador+1);
			contador = 0;
		}
	}
	return 0;
}

