//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1611


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int q = 0; q < ct; q++){
		int n, c, m;
		scanf("%d %d %d", &n, &c, &m);
		int vet[m];
		for(int i = 0; i < m; i++){
			scanf("%d", &vet[i]);
		}
		qsort(vet, m, sizeof(int), cmp);
		int aux = 0;
		long long ans = 0;
		for(int i = 0; i < m; i++){
			if(aux == 0){
				ans += vet[i]*2;
				aux = c;
			}
			aux--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

