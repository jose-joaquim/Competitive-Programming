//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2750

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

int n;
int memo[10000000];

int dp(int x){
	if(x == 0){
		return memo[x] = 1;
	}
	if(memo[x] != -1) return memo[x];

	return memo[x] = (dp((int) (x - sqrt(x))) + dp((int) log(x)) + dp((int) (x * pow(sin(x), 2))))%1000000;
}
int main(int argc, char **argv)
{
	memset(memo, -1, sizeof memo);
	while(scanf("%d", &n) && (n != -1)){
		printf("%d\n", dp(n));
	}
	return 0;
}

