//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1548

#include <stdio.h>
#include <stdlib.h>

void bubble(int *vet, int n)
{
	int i, j, temp;
	for(i = 0; i<n; i++) //i < n
		for(j = 0; j<n-1; j++) // i < n-1
			if(vet[j] < vet[j+1]){
				temp = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = temp;
			}
}

int main(int argc, char **argv)
{
	int x, i, *vetor, n, j, a;
	scanf("%d", &x);
	for(i=0;i<x;i++){
		scanf("%d", &n);
		vetor = (int *) malloc(n*sizeof(int));
		int aux[n];
		for(j=0;j<n;j++){
			scanf("%d", &vetor[j]);
			aux[j] = vetor[j];
		}
		bubble(vetor, n);
		a = n;
		for(j=0;j<n;j++){
			
			if(aux[j] != vetor[j]){
				a--;
			}
		}
		printf("%d\n", a);		
	}
	return 0;
}

