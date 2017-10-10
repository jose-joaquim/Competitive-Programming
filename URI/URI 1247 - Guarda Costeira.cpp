//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1247


#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;


int main(int argc, char **argv)
{
	int d, vf, vg;
	while(scanf("%d %d %d", &d, &vf, &vg) != EOF){
		double dist = hypot(d, 12);
		//printf("dist foi %.2lf\n", dist);
		double tl = 12.0/vf;
		double tg = dist/vg;
		//printf("tempo guarda eh %.2lf e tempo ladrao eh %.2lf\n", tg, tl);
		puts(tg <= tl ? "S" : "N");
	}
	return 0;
}

