#include <stdio.h>
#include "bubble.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	int p, i, j, start, andar = 0;
	int n = 0, a = 0;
	scanf("%d", &p);
	for(i=0; i<p;i++){
		int andares;
		scanf("%d", &andares);
		int vet[andares], predio;
		for(j=0;j<andares;j++){
			scanf("%d", &vet[andares]);
		}
		bubble(vet);
		for(i=0;i<8;i++){
			if(vet[i] < 0) n++;
			else p++;
		}
		int vetn[n], vetp[a];
		for(i=0;i<8;i++){
			if(vet[i] < 0){
				vetn[n] = vet[i];
				n++;
			}else{
				vetp[a] = vet[i];
				a++;
			}
		}
		a = 0;
		printf("%d %d\n", vetn[n-1], vetp[0]);
		if(vetp[a] > abs(vetn[n-1])){//se eu comecar com os negativos
			predio = vetn[n-1];
			start = 1;
			andar++;
			puts("aqui");
		}else{//se comecar com os positivos
			predio = vetp[0];
			start = 0;
			andar++;
			a++;
			puts("oi");
		}
		printf("%d\n", predio);
		
		/*while(1){
			if(start){//vou ver o menor positivo e comparar com o absoluto do negativo que esta aqui
				if(abs(predio) > vetp[a]){
					break;
				}else{
					predio = vetp[a];
					start = 0;
					a++;
					andar++;
				}
			}else{
				if(predio > abs(vetn[n-1])){
					break;
				}else{
					n--;
					predio = vetn[n];
					start = 1;
					andar++;
				}
			}								
		}
		printf("%d\n", andar);*/
	}
	return 0;
}

