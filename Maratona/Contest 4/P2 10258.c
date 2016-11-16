#include <stdio.h>
#include <stdlib.h>

typedef struct pax{
	int a;
	int b;
	int c;
	char Q;
	struct pax *prox;
}times;

int main(int argc, char **argv)
{
	int x, i, cont, prob, time;
	char L;
	scanf("%d", &x);
	for(i=0;i<x;i++){
		scanf("%d %d %d %c", &cont, &prob, &time, &L);
		
	}
	return 0;
}

