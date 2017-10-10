//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1715

#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
	int n, r;
	while(scanf("%d %d" , &n, &r) != EOF){
		bool matrix[n+10];
		memset(matrix, false, sizeof matrix);
		vector<int> indice;
		int ret = 0;
		for(int i = 0; i < r; i++){
			int k;
			cin >> k;
			matrix[k] = true;
			
		}
		for(int i = 1; i <= n; i++){
			if(!matrix[i]){
				//printf("%d nao retornou\n", i);
				indice.push_back(i);
				ret++;
			}
		}
		//printf("%lld\n", indice.size());
		if(indice.empty()){
			printf("*\n");
		}else{
			for(int i = 0; i < ret; i++){
				printf("%d ", indice[i]);
			}
			puts("");
		}
	}
	return 0;
}

