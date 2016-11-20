//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1933

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	int a, b;
	cin >> a >> b;
	if(a >= b){
		printf("%d\n", a);
	}else{
		printf("%d\n", b);
	}
	return 0;
}

