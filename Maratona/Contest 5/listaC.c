#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cel{
	int num;
	struct cel *prox;
}celula;

void inserirE(celula **p, int x){
	celula *aux;
	aux = (celula *) malloc(sizeof(celula));
	aux->num = x;
	(*p)->prox = aux;
	*p = (*p)->prox;
	aux->prox = NULL;
}

void imprime(celula *p){
	celula *aux;
	for(aux = p->prox; aux != NULL; aux = aux->prox){
		printf("%d\n", aux->num);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	celula *lista, *r; celula *lista2, *q;
	lista = (celula *) malloc(sizeof(celula));
	lista2 = (celula *) malloc(sizeof(celula));
	r = lista; q = lista2;
	int a, i;
	for(i=0;i<5;i++){
		scanf("%d", &a);//escolhendo os números a serem inseridos na primeira lista
		inserirE(&r, a);//inserindo elemento em 1 lista...
		inserirE(&q, rand()%400);//inserindo agora na outra
	}
	//imprime(lista);
	r->prox = lista2->prox;
	puts("");
	imprime(lista); //LISTA JÁ CONCATENADA
	return 0;
}
