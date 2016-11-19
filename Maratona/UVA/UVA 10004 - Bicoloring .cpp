//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=945

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(int argc, char **argv)
{
	int v, e, k, l;
	while(scanf("%d", &v) && v != 0){
		bool stop = false;
		cin >> e;
		vector<vector<int> > AdjMatrix(v, vector<int>(v, 0));
		for(int i = 0; i < e; i++){
			scanf("%d %d", &k, &l);
			AdjMatrix[k][l] = 1;
			AdjMatrix[l][k] = 1;
		}
		queue<int> q; q.push(0);
		vector<int> inf(v, 0);
		vector<int> niveis(v, 0);
		inf[0] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(int j = 0; j < v; j++){
				if(AdjMatrix[u][j] == 1){
					if(inf[j] == 0){//se x não é marcado
						inf[j] = 1;
						q.push(j);
						niveis[j] = niveis[u] + 1;
					}else{
						if(niveis[j] == niveis[u]){
							printf("NOT BICOLORABLE.\n");
							stop = true;
							break;							
						}
					}					
				}		
			}
			if(stop) break;	
		}
		if(!stop) puts("BICOLORABLE.");
	}
	return 0;
}

