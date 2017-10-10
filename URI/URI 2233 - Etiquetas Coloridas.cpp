//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2233

#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>

using namespace std;

typedef long long ll;

int main(int argc, char **argv)
{
	ll a, b, c;
	while(cin >> hex >> a >> b >> c){
		if(b > a){
			cout << hex << 1 << endl;
		}else if(a >= b && b >= c){
			ll g_r = a / b;
			ll b_g = b / c;
			cout << hex << 1 + (g_r * g_r)*(b_g * b_g) + (g_r * g_r) << endl;
		}else if(a >= b && b < c){
			ll g_r = a / b;
			cout << hex << 1 + (g_r * g_r) << endl;
		}
	}
	return 0;
}

