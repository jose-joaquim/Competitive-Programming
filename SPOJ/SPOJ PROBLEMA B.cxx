#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
	int n, j;
	while(scanf("%d %d", &n, &j) && (n || j)){
		int vez = 1;
		vector<pair<int, int> > jogador_topo_qtd(j+1);
		for(int i = 1; i <= j; i++){
			jogador_topo_qtd[i].first = -1;
			jogador_topo_qtd[i].second = 0;
		}
		int descarte[14];
		memset(descarte, 0, sizeof descarte);
		for(int i = 0; i < n; i++){
			int carta_vez;
			scanf("%d", &carta_vez);
			if(descarte[carta_vez] > 0){// se a carta da vez estiver na carta de descarte
				descarte[carta_vez]--;
				jogador_topo_qtd[vez].first = carta_vez;
				jogador_topo_qtd[vez].second += 2;
				continue;
			}
			bool achou = false;
			for(int q = 1; q <= j; q++){
				if(jogador_topo_qtd[q].first == carta_vez && q != vez){//se a carta da vez for a do topo de alguem
					jogador_topo_qtd[vez].second += jogador_topo_qtd[q].second + 1;//pega o monte dele + carta da vez
					jogador_topo_qtd[vez].first = carta_vez;
					jogador_topo_qtd[q].second = 0;
					jogador_topo_qtd[q].first = -1;
					achou = true;
				}
			}
			if(achou) continue;
			if(jogador_topo_qtd[vez].first == carta_vez){
				jogador_topo_qtd[vez].second++;
				continue;
			}
			descarte[carta_vez]++;
			vez++;
			if(vez == j + 1){
				vez = 1;
			}
		}
		int ans = -1;
		for(int i = 1 ; i <= j; i++){
			ans = max(ans, jogador_topo_qtd[i].second);
		}
		printf("%d ", ans);
		for(int i = 1; i <= j; i++){
			if(jogador_topo_qtd[i].second == ans) printf("%d ", i);
		}
		puts("");
	}
	return 0;
}

