#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <map>
#include <sstream>
#include <cmath>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vector<ii> > AdjList;
//vector<vi> AdjList;

bool bb(vector<int> &A, int num){
	int ini = 0, fim = A.size()-1, mid;
	while(ini <= fim){
		mid = (int)(ini + fim)/2;
		if(A[mid] == num){
			//puts("akjsd");
			return true;
		}
		
		if(num < A[mid]){
			fim = mid - 1;
		}else{
			ini = mid + 1;
		}
	}
	return false;
}

int main(int argc, char **argv)
{
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		AdjList.assign(k, vector<ii>());
		vector<int> times;
		int aux;
		char s[1200];
		for(int i = 0; i < n; i++){
			cin >> aux;
			times.push_back(aux);
		}
		/*printf("%d\n", times[1]);
		system("pause");*/
		fflush(stdin);
		aux = 0;
		gets(s);
		while(aux < n){
			fflush(stdin);
			char *pch = strtok(s, " ");
			while(pch != NULL){
				int v = atoi(pch);
				//printf("%d %d %d\n", v, times[aux], v*times[aux]);
				AdjList[aux].push_back(make_pair(v, v*times[aux]));
				pch = strtok(NULL, " ");
			}
			aux++;
			gets(s);
		}
		//printf("%d KK\n", AdjList[0][6].second);
		vi dist(k, INF); dist[0] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, 0));
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if(d > dist[u]) continue;
			//puts("xxx");
			for(int i = 0; i < (int) AdjList[u].size(); i++){
				ii v = AdjList[u][i];
				//printf("%d %d %d\n", dist[u], v.first, dist[v.second]);
				if(dist[u] + v.second + 60 < dist[v.first]){
					//puts("entrei");
					dist[v.first] = dist[u] + v.second + 60;
					pq.push(ii(v.first, dist[v.first]));
				}
			}
		}
		for(int i = 0; i < k; i++){
			printf("%d ", dist[i]);
		}
		puts("");
		printf("OIE %d\n", dist[k]);
		/*AdjList.assign(n, vector<ii>());
		vector<int> times;
		vector<vi> floors;
		floors.assign(n, vi());
		vi destinos, results;
		int aux;
		char s[1000];
		for(int i = 0; i < n; i++){
			cin >> aux;
			times.push_back(aux);
		} 
		fflush(stdin);
		aux = 0;
		gets(s);
		while(aux < n){
			//if(!strcmp(s, "\n")) break;
			fflush(stdin);
			char *pch = strtok(s, " ");
			while(pch != '\0'){
				//int K = atoi(pch);
				//printf("K EH %d\n", K);
				floors[aux].push_back(atoi(pch));
				//printf("colocando em %d\n", aux);
				//puts("oi");
				pch = strtok(NULL, " ");
			}
			aux++;
			//printf("aux eh %d\n", aux);
			gets(s);
		}
		//puts("asXXdas");
		for(int l = 0; l < n; l++){
			for(int i = 0; i < (int)floors[l].size(); i++){//to no vertice (elevador) l, e vou
				//puts("FORFOR");
				int floor = floors[l][i];				   //observar os i's andares que ele passa
				for(int j = l+1; j < n; j++){
					//printf("to comparando o elevador %d com %d\n", l, j);
					//printf("vou procurar pelo andar %d no elevador %d\n", floor, j);
					if(bb(floors[j], floor)){//se o elevador l tem um andar em coincidencia com o elevador j, entao conecto eles
						//puts("nada");
						//printf("vou inserir %d e %d em %d\n", j, floor, l);
						AdjList[l].push_back(make_pair(j, floor));//j eh o andar destino, floor eh o andar
					}						
				}
			}
		}
		//puts("kk");
		//agora vou verificar quais dos elevadores possuem o andar final
		//eu poderia ter feito isso dentros dos for's acima, mas so pra nao ficar 
		//mais complexo vou fazer aqui mesmo num O(V + E)
		for(int i = 0; i < n; i++){
			for(int j = 0; j < (int) floors[i].size(); j++){
				//printf("comparando %d com %d\n", floors[i][j], k);
				if(floors[i][j] == k){//se o vertice destino (AdjList[i][j].first) vai ate o andar destino
					destinos.push_back(floors[i][j]);//eu o coloco na lista de destinos
					//printf("vou adicionar em %d com %d e %d\n", i, j, floors[i][j]);
					AdjList[i].push_back(make_pair(j, k));
				}
			}
		}
		
		for(int i = 0; i < (int) destinos.size(); i++){//faço um dijkstra pra cada destino e depois vejo qual o menor deles
			puts("entrei aqui");
			vi dist(n, INF); dist[0] = 0;
			priority_queue<ii, vector<ii>, greater<ii> > pq;
			pq.push(ii(0, 0));
			//int andarAtual = 0;
			while(!pq.empty()){
				ii front = pq.top(); pq.pop();
				int d = front.first, u = front.second;//d eh o peso (no caso, o andar atual) e u eh o vertice origem
				//printf("%d %d\n", d, u);
				if(d > dist[u]) continue;
				//printf("d eh %d e u eh %d\n", d, u);
				for(int j = 0; j < (int) AdjList[u].size(); j++){
					ii v = AdjList[u][j];
					if(dist[u] + (fabs(v.second - d) * times[v.first]) < dist[v.first]){//a multiplicacao nos parenteses siginfica lá o tempo das paradas
						dist[v.first] = dist[u] + (fabs(v.second - d) * times[v.first]);
						pq.push(ii(dist[v.first], v.first));
					}
				}
			}
			results.push_back(dist[destinos[i]]);
		}
		puts("eoq");
		for(int i = 0; i < (int) results.size(); i++){
			printf("%d ", results[i]);
		}*/
	}
	return 0;
}
