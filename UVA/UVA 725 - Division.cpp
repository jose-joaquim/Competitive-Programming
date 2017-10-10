//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=666

#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	int N, cont, atual, aux;
	bool nao = false; int sol = 0;
	cin >> N;
	while(N != 0){
		for(int i = 01234; i < 98765; i++){
			bool vetAux[10]; cont = 0; nao = false;
			for(int j = 0; j < 10; j++){
				vetAux[j] = false;
			}
			aux = atual = N*i;
			if(atual <= 98765){
				while(cont < 5){
					int pos = aux%10;
					if(vetAux[pos] == true){
						nao = true;
						break;
					}else vetAux[pos] = true;
					aux = (int)aux/10;
					cont++;
				}
				cont = 0;
				int seila = i;
				while(cont < 5){					
					int pos = seila%10;
					if(vetAux[pos] == true){
						nao = true;
						break;
					}else vetAux[pos] = true;
					seila = (int)seila/10;
					cont++;
				}
			}else break;
			if(!nao){
				printf("%05d / %05d = %d\n", atual, i, N);
				sol++;
			}
		}
		
		if(!(sol > 0)) printf("There are no solutions for %d\n\n", N);
		printf("\n");
		sol = 0;
		cin >> N;
	}
	
	return 0;
}

