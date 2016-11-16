#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	int n, p;
	while(scanf("%d %d", &n, &p) && (n || p)){
		vector<stack<int> > vet;
		vet.assign(p, stack<int>());
		int belongs = -1, pos = -1;
		for(int i = 0; i < p; i++){
			int qtd;
			scanf("%d", &qtd);
			for(int j = 0; j < qtd; j++){
				int u;
				scanf("%d", &u);
				vet[i].push(u);
				if(u == 1){
					pos = j;
					belongs = i;
				}
			}
		}
		int ans = 0;
		int totalDireita = 0, totalEsquerda = 0;
		//vendo o lado totalDireita
		for(int i = belongs - 1; i >= 0; i--){
			int size = (int) vet[i].size();
			if(size - pos <= 0) break;
			totalEsquerda += size - pos;
		}
		for(int i = belongs + 1; i < p; i++){
			int size = (int) vet[i].size();
			if(size - pos <= 0) break;
			totalDireita += size - pos;
		}
		ans = min(totalEsquerda, totalDireita);
		while(vet[belongs].top() != 1){
			vet[belongs].pop();
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

