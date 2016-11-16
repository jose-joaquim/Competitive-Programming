#include <stdio.h>

int main()
{
	int qtd, x, i, j, div = 0;
	scanf("%d", &qtd);
	for(i = 0; i<qtd; i++){
		scanf("%d", &x);
		div = 0;
		  for (j = 1; j <= x; j++) {
			if (x % j == 0) { 
			 div++;
			}
		  }
		  
		  if (div == 2)
			printf("%d eh primo\n", x);
		  else
			printf("%d nao eh primo\n", x);
	}
	return 0;
}

