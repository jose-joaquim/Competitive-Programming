//Author/Autor: Jos? Joaquim de Andrade Neto
//Link da quest?o: https://www.urionlinejudge.com.br/judge/pt/problems/view/1089

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int ct;
	while(scanf("%d", &ct) && ct){
		int vet[ct], loops = 0;
		int ori[ct]; //vai guardar se tá subindo ou descendo
		for(int i = 0; i < ct; i++){
			scanf("%d", &vet[i]);
		}
		
		/*if(vet[0] > vet[1]){//descendo
			ori = 0;
		}else ori = 1;*/
				
		for(int i = 0; i < ct; i++){
			/*if(i == ct - 1){
				if(vet[i] 
			}*/
			if(i == ct - 1){
				//puts("oie");
				if(vet[i] > vet[0]){
					//printf("%d eh maior que %d\n", vet[i], vet[0]);
					ori[i] = 0;
				}else{
					//printf("%d eh MENOR que %d\n", vet[i], vet[0]);
					//printf("entrei\n");
					ori[i] = 1;
				}
			}else{
				if(vet[i] > vet[i+1]){//descendo
					//printf("%d eh maior que %d\n", vet[i], vet[i+1]);
					ori[i] = 0;
				}else{
					//printf("%d eh MENOR que %d\n", vet[i], vet[i+1]);
					ori[i] = 1;
				}
			}
		}
		
		for(int i = 0; i < ct; i++){
			if(i == ct - 1){
				if(ori[i] != ori[0]){
					loops++;
				}
			}else{
				if(ori[i] != ori[i+1]){
					loops++;
				}
			}
		}
		
		printf("%d\n", loops);
		/*for(int i = 0; i < ct; i++){
			printf("%d ", ori[i]);
		}
		puts("");*/
		/*for(int i = 1; i < ct; i++){
			if(i == ct - 1){
				if(
			}else{
				
			}
		}*/
	}
	return 0;
}

