//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1921
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <map>
#include <algorithm>

using namespace std;

double memo[26][105];
char lineQuery[500];
double p;
int op, qtdNecessaria, colP;
vector<int> itemsForPrice;
vector<double> price;
vector<int> querys;

double solve(int pos_item, int qtd_pega){
	//printf("%d %d\n", pos_item, qtd_pega);
	if(qtd_pega <= 0){
		return 0;
	}
	
	if(pos_item < 0){
		return 1000000000;
	}
	
	if(memo[pos_item][qtd_pega] != -1){
		return memo[pos_item][qtd_pega];
	}
	
	double ans = 1000000000.0;
	int taken;
	for(int i = 0; ; i++){
		taken = i*itemsForPrice[pos_item];
		ans = min(ans, i*price[pos_item] + solve(pos_item - 1, qtd_pega - taken));
		if(taken >= qtd_pega){
			break;
		}
	}
	
	return memo[pos_item][qtd_pega] = ans;
}

int main(int argc, char **argv)
{
	int cc = 0;
	while(scanf("%lf %d", &p, &op) != EOF){
		
		itemsForPrice.clear();
		price.clear();
		querys.clear();
		
		itemsForPrice.push_back(1);
		price.push_back(p);
		
		for(int i = 0; i < op; i++){
			double u; int qtd;
			scanf("%d %lf", &qtd, &u);
			itemsForPrice.push_back(qtd);
			price.push_back(u);
		}
		
		getchar();
		fgets(lineQuery, 500, stdin);
		char *ptr = strtok(lineQuery, " ");
		
		while(ptr != NULL){
			int n = atoi(ptr);
			querys.push_back(n);
			ptr = strtok(NULL, " ");
		}
		printf("Case %d:\n", ++cc);
		
		//map<int, double> ans;
		
		for(int i = 0; i < 26; i++)
				for(int j = 0; j < 105; j++)
					memo[i][j] = -1;
		
		for(int i = 0; i < (int) querys.size(); i++){
			if(memo[op][querys[i]] == -1) solve(op, querys[i]);		
			printf("Buy %d for $%.2lf\n", querys[i], memo[op][querys[i]]);
		}
	}
	return 0;
}

