//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

vector<vector<int> > memo;
vector<int> vi;
int x;

int val(int id, int remW){
	if(id == x || remW == 0) return 0;
	if(memo[id][remW] != -1) return memo[id][remW];
	if(vi[id] > remW) return memo[id][remW] = val(id + 1, remW);
	
	return memo[id][remW] = max(val(id + 1, remW), vi[id] + val(id + 1, remW - vi[id]));
}

int main(int argc, char **argv)
{
	int ct;
	cin >> ct;
	while(ct--){
		vi.clear();
		int k, sum = 0;
		cin >> x;
		for(int i = 0; i < x; i++){
			cin >> k;
			vi.push_back(k);
			sum += k;
		}
		vector<int> amounts(sum/2+1, -1);
		memo.assign(x, amounts);
		printf("%d\n", sum-2*val(0, sum/2));
	}
	return 0;
}

