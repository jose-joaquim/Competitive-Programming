//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2089
//OS CASOS DE TESTE DESSA QUESTÃO PODEM ESTAR FRACOS, POIS NÃO DEVERIA PASSAR
//THE TEST CASES OF THIS QUESTION ARE WEAK, BECAUSE SHOULD BE WRONG ANSWER

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, V, x;
vector<int> coins;
int price;
bool deu;
//int memo[100000 + 10];
//já usei memo[X][Y] mas dá wa 100% por causa do limite de memória

void pay(int c, int value_now){
	/*x++;
	printf("%d oie\n", value_now);*/
	if(value_now > N){
		return;// 1000000000;
	}
	if(value_now == N){
		deu = true;
		return;// 0;
	}
	/*if(memo[value_now] != -1){
		//puts("entrei aqui");
		return memo[value_now];
	}*/
	for(int i = c; i < V; i++){
		/*memo[value_now] = */pay(i+1, value_now + coins[i]);
		if(deu) return;// memo[value_now];
	}
	
	return;// memo[value_now];
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &N, &V) && (N || V)){
		//memset(memo, -1, sizeof memo);
		coins.clear();
		int k;
		deu = false;
		for(int i = 0; i < V; i++){
			cin >> k;
			coins.push_back(k);
		}
		pay(0, 0);
		puts(deu ? "sim" : "nao");
		//printf("chamadas %d\n", x);
	}
	return 0;
}

