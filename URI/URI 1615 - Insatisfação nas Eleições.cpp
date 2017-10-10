//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1615


#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int q = 0; q < ct; q++){
		int n, m;
		scanf("%d %d", &n, &m);
		int votos[n], maior = -1, vt = -1;
		memset(votos, 0, sizeof votos);
		for(int i = 0; i < m; i++){
			int x;
			scanf("%d", &x);
			votos[x-1]++;
		}
		for(int i = 0; i < n; i++){
			if(votos[i] > vt){
				vt = votos[i];
				maior = i;
			}
		}
		double a = ((double)vt/(double)m)*100.0;
		if(a <= 50.0){
			printf("-1\n");
			continue;
		}else{
			printf("%d\n", maior+1);
		}
		
	}
	return 0;
}

