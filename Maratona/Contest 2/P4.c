#include <stdio.h>
#include <stdlib.h>

int palindromo(int x){
	int ret = 0, aux = x;
	
	while (aux != 0) {
		ret = ret * 10 + aux % 10;  /* acrescenta mais um digito a direita */
		aux = aux / 10;                     /* joga fora esse digito */
	}
	return ret;
}

int ehpal(int x){
	int ret = 0, aux = x;
	
	while (aux != 0) {
		ret = ret * 10 + aux % 10;  /* acrescenta mais um digito a direita */
		aux = aux / 10;                     /* joga fora esse digito */
	}
	
	if(ret == x){
		return 1;
	}else return 0;
		
	return 0;
}

int main(int argc, char **argv)
{
	int x, i, a, vez;
	scanf("%d", &x);
	int vet[x];
	for(i = 0; i < x; i++){
		scanf("%d", &vet[i]);
	}
	for(i = 0; i < x; i++){
		a = 0;
		vez = vet[i];
		while(1){							
			vez += palindromo(vez);
			a++;			
			if(ehpal(vez)){
				printf("%d %d\n", a, vez);
				break;
			}
		}		
	}
	return 0;
}
