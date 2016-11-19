//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1708

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		int dy = 0, dx = 0;
		
		int volta = 1;
		while(true){
			if((dy - dx) >= x) break;
			dx += x;
			dy += y;
			volta++;
		}
		
		printf("%d\n", volta);
	}
	return 0;
}

