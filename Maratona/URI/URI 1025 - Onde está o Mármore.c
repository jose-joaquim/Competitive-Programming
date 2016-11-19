//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1025

#include <stdio.h>
#include <stdlib.h>

int cmp (const void *x, const void *y){
   return (*(int *)x - *(int *)y); 
}


int BB(int vet[], int chave, int Tam){
     int inf = 0;     
     int sup = Tam-1;
     int meio; int a;
     while (inf <= sup) 
     {
          meio = (inf + sup)/2;
          if (chave == vet[meio]){
			  a = 1;
			  while(vet[meio] == vet[meio-a]){
				  meio -= a;
			  }
			  return meio;
		  }
          if (chave < vet[meio])
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;
}

int main(int argc, char **argv)
{
	int n, q, i, a, j = 1;
	scanf("%d %d", &n, &q);
	while(n != 0 && q != 0){
		int vetor[n], quest[q];
		for(i=0;i<n;i++){
			scanf("%d", &vetor[i]);
		}
		for(i=0;i<q;i++){
			scanf("%d", &quest[i]);
		}
		qsort(&vetor, n, sizeof(int), cmp);
		printf("CASE# %d:\n", j);
		j++;
		i = 0;
		while(q != 0){			
			a = BB(vetor, quest[i], n);
			if(a != -1){
				printf("%d found at %d\n", quest[i], (a+1));
			}else{
				printf("%d not found\n", quest[i]);
			}
			i++;
			q--;
		}
		scanf("%d %d", &n, &q);
	}
	return 0;
}

