//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2238


#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	int a, b, c, d;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
		vector<long long> divisors;
		long long ans = 1000000000;
		 for (int i=1; i<=sqrt(c)+1; i++){
			if (c%i==0){
				divisors.push_back(i);
				if (c/i != i){
					divisors.push_back(c/i);
				}
			}
		}
		
		for(long long i = 0; i < (long long) divisors.size(); i++){
			if(divisors[i]%a==0 && divisors[i]%b!=0 && c%divisors[i]==0 && d%divisors[i]!=0){
				ans = min(ans, divisors[i]);
			}
		}
		if(ans == 1000000000){
			puts("-1");
		}else printf("%lld\n", ans);
	}
	return 0;
}

