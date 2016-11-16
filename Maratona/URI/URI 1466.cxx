#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

typedef struct n{
	int valor;
	struct n *esq;
	struct n *dir;
}arvore;

void insere(arvore **no, int numero){
	if(*no == NULL){
		(*no) = (arvore *) malloc(sizeof(arvore));
		(*no)->valor = numero;
		(*no)->esq = NULL;
		(*no)->dir = NULL;
	}else{
		if(numero < (*no)->valor){
			insere(&(*no)->esq, numero);
		}else{
			insere(&(*no)->dir, numero);
		}
	}
}

int c, m, x;

void bfs(arvore *no){
	queue<arvore *> q;
	printf("%d", no->valor);
	if(no->esq != NULL) q.push(no->esq);
	if(no->dir != NULL) q.push(no->dir);
	while(!q.empty()){
		arvore *u = q.front(); q.pop();
		printf(" %d", u->valor);
		if(u->esq != NULL) q.push(u->esq);
		if(u->dir != NULL) q.push(u->dir);		
	}
	puts("");
}

int main(int argc, char **argv)
{
	scanf("%d", &c);
	x = c;
	bool quebra = false;
	for(int q = 1; q <= c; q++){
		arvore *ar = NULL;
		scanf("%d", &m);
		if(!quebra) quebra = true;
		else printf("\n");
		//puts("sdlkfn");
		for(int i = 0; i < m; i++){
			int x;
			scanf("%d", &x);
			insere(&ar, x);
			//puts("oi");
		}
		//puts("alskndQQQ");
		printf("Case %d:\n", q);
		bfs(ar);
	}
	puts("");
	return 0;
}

