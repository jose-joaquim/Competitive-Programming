//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1608


#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int q = 0; q < ct; q++){
		int d, i, b;
		scanf("%d %d %d", &d, &i, &b);
		int unit_price[i], bolo[b];
		memset(bolo, 0, sizeof bolo);
		for(int j = 0; j < i; j++){
			scanf("%d", &unit_price[j]);
		}
		for(int j = 0; j < b; j++){
			int u;
			scanf("%d", &u);
			for(int k = 0; k < u; k++){
				int x, v;
				scanf("%d %d", &x, &v);
				bolo[j] += unit_price[x]*v;
			}
		}
		qsort(bolo, b, sizeof(int), cmp);
		printf("%d\n", (int)d/bolo[0]);
	}
	return 0;
}

