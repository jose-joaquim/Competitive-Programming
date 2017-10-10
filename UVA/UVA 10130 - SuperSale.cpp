//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1071

#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>

using namespace std;

vector<int> V, W;
vector<int> maxW;
int N;
int memo[1010][40];

int val(int id, int remW){
	if(id == N || remW == 0) return 0;
	if(memo[id][remW] != -1) return memo[id][remW];
	if(W[id] > remW) 		 return memo[id][remW] = val(id + 1, remW);
	return memo[id][remW] = max(val(id + 1, remW), V[id] + val(id + 1, remW - W[id]));
}

int main(int argc, char **argv)
{
	int ct;
	cin >> ct;
	while(ct--){
		memset(memo, -1, sizeof memo);
		V.clear(); W.clear(); maxW.clear();
		int a, b, persons, ans = 0, MW;
		cin >> N;
		
		for(int i = 0; i < N; i++){
			cin >> a >> b;
			V.push_back(a);
			W.push_back(b);
		}
		
		cin >> persons;
		while(persons--){
			cin >> MW;
			ans += val(0, MW);
		}
		printf("%d\n", ans);
	}
	return 0;
}

