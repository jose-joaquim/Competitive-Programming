//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1833

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b){ return a * (b / gcd(a, b)); }

/*long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}*/

int main(int argc, char **argv)
{
	//printf("%d\n", lcm(6, 8));
	int n;
	while(scanf("%d", &n) && n){
		int qtd = 0;
		vector<int> divisors;
		for(int i = 1; i <= (int)sqrt(n); i++){
			if(n%i == 0){
				divisors.push_back(i);
				if(i != n/i) divisors.push_back(n/i);
			}
		}
		for(int i = 0; i < (int) divisors.size(); i++){
			for(int j = 0; j <= i; j++){
				if(lcm(divisors[i], divisors[j]) == n) qtd++;
			}
		}
		printf("%d %d\n", n, qtd);
	}
	return 0;
}

