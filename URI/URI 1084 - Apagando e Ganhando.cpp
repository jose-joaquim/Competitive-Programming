//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1084

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <stack>
#include <deque>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	int n, d;
	while(scanf("%d %d", &n, &d) && (n || d)){
		int i;
		char numero[100005], pilha[100005];
		int top = -1;
		scanf("%s", numero);
		for(i = 0; i < n; i++){
			while(d && top != -1 && pilha[top] < numero[i]){
				d--;
				top--;
			}
			pilha[++top] = numero[i];
		}
		top -= d;
		pilha[top+1] = 0;
		printf("%s\n", pilha);
	}
	return 0;
}

