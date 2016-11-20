//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1936

#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int fatorial(int numero) //O calculo do fatorial e feito aqui
{
   int aux;
   aux = numero;
   while(numero > 1)
   {
      aux = aux * (numero-1);
      numero--;
   }
   return (aux);
}

int main(int argc, char **argv)
{
	int N;
	cin >> N;
	int k = 0, x = 8;
	while(N > 0){
		if(fatorial(x) > N){			
			x--;
			continue;
		}else{
			N -= fatorial(x);
			k++;
		}		
	}
	cout << k << endl;
	return 0;
}

