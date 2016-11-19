//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1148

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int sameCountry[505][505];

bool isSameCountry(int u, int v){
	return sameCountry[u][v] == 1 && sameCountry[v][u] == 1;
}

int main(int argc, char **argv)
{
	int N, E;
	while(scanf("%d %d", &N, &E) && (N || E)){
		vector<vii> AdjList;
		AdjList.assign(N, vii());
		int nQ;
		int visited[N][N];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				sameCountry[i][j] = INF;
			}
		}
		
		for(int i = 0; i < E; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			AdjList[u-1].push_back(ii(v-1, w));
			sameCountry[u-1][v-1] = 1;
		}
		
		scanf("%d", &nQ);
		for(int k = 0; k < nQ; k++){
			int from, to;
			scanf("%d %d", &from, &to);
			
			if(isSameCountry(from-1, to-1)){
				printf("0\n");
				continue;
			}
			
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					visited[i][j] = 0;
				}
			}
			
			vi dist(N, INF); dist[from-1] = 0;
			priority_queue<ii, vector<ii>, greater<ii> > pq;
			pq.push(ii(0, from-1));
			
			while(!pq.empty()){
				ii front = pq.top(); pq.pop();
				int d = front.first; int u = front.second;
				if(d > dist[u]) continue;
				for(int i = 0; i < (int) AdjList[u].size(); i++){
					ii v = AdjList[u][i];
					if(!visited[u][v.first]){
						if(isSameCountry(u, v.first)){
							dist[v.first] = dist[u];
							pq.push(ii(0, v.first));
							visited[u][v.first] = 1;
							visited[v.first][u] = 1;
						}else{
							if(dist[u] + v.second < dist[v.first]){
								dist[v.first] = dist[u] + v.second;
								pq.push(ii(dist[v.first], v.first));
								visited[u][v.first] = 1;
							}						
						}
					}
				}
			}
			if(dist[to-1] == INF){
				printf("Nao e possivel entregar a carta\n");
			}else{
				printf("%d\n", dist[to-1]);
			}
		}
		puts("");
		
	}
	return 0;
}

