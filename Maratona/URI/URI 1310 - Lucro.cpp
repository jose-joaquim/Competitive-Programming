//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1310


#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int n;
	while(scanf("%d", &n) != EOF){
		int cost;
		scanf("%d", &cost);
		int costPerDay[n];
		for(int i = 0; i < n; i++){
			scanf("%d", &costPerDay[i]);
		}
		int ans = -1000000000, sum = 0;
		for(int i = 0; i < n; i++){
			sum += costPerDay[i] - cost;
			if(sum < 0) sum = 0;
			ans = max(ans, sum);
			
		}
		printf("%d\n", ans);
	}
	return 0;
}

