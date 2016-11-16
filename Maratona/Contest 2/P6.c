#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int h1, h2, m1, m2, soma, aux;
	scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
	while(h1 != 0 || h2 != 0 || m1 != 0 || m2 != 0){
		soma = 0;
		if(h1 == h2){
			if(m2 > m1)
				printf("%d\n", (m2-m1));
			else 
				printf("%d\n", 1440+(m2-m1));
		}else if(h1 < h2){// ex: 19 23
			soma = (h2-h1)*60;
			if(m1 > m2)
				soma += m2-m1;
			else
				soma += m2 - m1;
			printf("%d\n", soma);
		}else if(h1 > h2){// ex: 23 19
			aux = 24 - h1;
			aux += h2;
			soma = aux*60;
			if(m1 > m2)
				soma -= m1 - m2;
			else
				soma += m2 - m1;
			printf("%d\n", soma);
		}		
		scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
	}
	return 0;
}

