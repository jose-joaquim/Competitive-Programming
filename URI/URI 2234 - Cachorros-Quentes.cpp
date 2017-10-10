//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2234

#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	double a, b;
	while(scanf("%lf %lf", &a, &b) != EOF){
		printf("%.2lf\n", a/b);
	}
	return 0;
}

