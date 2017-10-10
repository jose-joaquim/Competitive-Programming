#include <stdio.h>
#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

/* a deve ser maior que b */
int encaixa(int a, int b) {
  while ((b != 0) && (a % 10 == b % 10)) {
    a = a/10;
    b = b/10;
  }
  if (b == 0) 
    return TRUE;
  else
    return FALSE;
}

bool seila(int a, int b){
	int maior,
    ehSubseq = FALSE ;

	  maior = a;
	  if (a < b) {
		a = b;
		b = maior;
		maior = a; // guarda maior entre a e b 
	  }

	  while ((maior >= b) && (ehSubseq == FALSE)) {
		if (encaixa(maior, b) == TRUE)
		  ehSubseq = TRUE;
		maior = maior/10;
	  }
	  
	  if (ehSubseq == TRUE)
		return true;
	  else
		return false;
	
	return false;
}

int main(){    
	int x, cont = 0; 
	cin >> x;
	for(int i = 1; i <= x; i++){
		cont++;		
		if(i == 4){
			cont++;
		}else if(i == 13){
			cont++;
		}else if(i > 13){
			if(seila(i, 4) || seila(i, 13)){				
				cont++;
			}
		}
	}
	while(seila(cont, 4) || seila(cont, 13)) cont++;
	cout << cont << endl;
	return 0;
}
