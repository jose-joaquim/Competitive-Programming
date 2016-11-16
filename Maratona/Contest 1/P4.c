#include <stdio.h>

int main()
{
	int qtd, x, y, i, sum;
	int j;
	scanf("%d", &qtd);
	for(j=0; j<qtd; j++){
		sum = 0;
		scanf("%d", &x);
		scanf("%d", &y);
		if(x == y){
			printf("0\n");
		}
		if(x < y){
			for(i = x+1; i<y; i++){
				if(i%2){
					sum += i;
				}
			}	
			printf("%d\n", sum);
		}else if(x > y){
			for(i = y+1; i<x; i++){
				if(i%2){
					sum += i;
				}
			}	
			printf("%d\n", sum);
		}
	}
	return 0;
}

