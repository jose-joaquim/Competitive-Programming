//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1132

#include <stdio.h>

int main(int argc, char **argv)
{
	int x, y;
	int i, sum = 0;
	scanf("%d %d", &x, &y);
	if(x < y){
		for(i = x; i <= y; i++){
			if(i%13 != 0){ 
				sum += i;
			}
		}
	}else if(x > y){
		for(i = y; i <= x; i++){
			if(i%13 != 0){ 
				sum += i;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}

