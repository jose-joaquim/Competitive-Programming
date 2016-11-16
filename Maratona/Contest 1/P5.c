#include <stdio.h>
	
int main(int argc, char **argv)
{
	int x, i, s1 = 0, s2 = 1, soma;
	scanf("%d", &x);
	if(x == 1){
		puts("0");
	}else if(x == 2){
		puts("0 1");
	}else{
		printf("0 1");
		for(i = 0; i<x-2; i++){
			soma = s1 + s2;
			printf(" %d", soma);
			s1 = s2;
			s2 = soma;
		}
		puts("");
	}	
	return 0;
}

