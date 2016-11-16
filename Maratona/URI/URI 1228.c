#include <stdio.h>

typedef struct v{
	int pos;
	int rel;
}carro;

int main(int argc, char **argv)
{
	int ct;
	while(scanf("%d", &ct) != EOF){
		int i, j, tmp, change = 0;
		carro cars[ct]; int aux[ct];
		for(i = 0; i < ct; i++){
			scanf("%d", &j);
			cars[j].pos = i;
		}
		for(i = 0; i < ct; i++){
			scanf("%d", &aux[i]);
		}
		for(i = ct - 1; i >= 1; i--){
			for(j = 0; j < i; j++){
				if(cars[aux[j]].pos > cars[aux[j+1]].pos){
					change++;
					tmp = aux[j];
					aux[j] = aux[j+1];
					aux[j+1] = tmp;
				}					
			}
		}
		printf("%d\n", change);
	}
	return 0;
}

