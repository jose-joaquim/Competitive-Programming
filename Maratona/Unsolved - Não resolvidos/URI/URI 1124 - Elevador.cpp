//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1024

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int l, c, r1, r2;
	while(scanf("%d %d %d %d", &l, &c, &r1, &r2) && l){
		double diagonal = sqrt(hypot(pow(l, 2), pow(c, 2)));
		double soma = r1*2.0 + r2*2.0;
		//printf("diagonal eh %.3lf e soma eh %.3lf\n", diagonal, soma);
		if(soma > diagonal) puts("N");
		else puts("S");
	}
	return 0;
}

