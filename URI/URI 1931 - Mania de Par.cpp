//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1931

#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#include <vector>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int c, k;
vector<vii> AdjList;
vector<vii> AdjList2;

void modifyGraph(){
	AdjList2.assign(c, vii());
	for(int q = 0; q < c; q++){
		for(int i = 0; i < (int) AdjList[q].size(); i++){
			ii front = AdjList[q][i];
			for(int j = 0; j < (int) AdjList[front.first].size(); j++){
				ii v = AdjList[front.first][j];
				AdjList2[q].push_back(ii(v.first, front.second + v.second));
			}
		}
	}
}

int main(int argc, char **argv)
{
	scanf("%d %d", &c, &k);
	AdjList.assign(c, vii());
	for(int i = 0; i < k; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		AdjList[u-1].push_back(ii(v-1, w));
		AdjList[v-1].push_back(ii(u-1, w));
	}
	modifyGraph();
	vi dist(c, INF); dist[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, 0));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first; int u = front.second;
		if(d > dist[u]) continue;
		for(int j = 0; j < (int) AdjList2[u].size(); j++){
			ii v = AdjList2[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	printf(dist[c-1] == INF ? "-1\n" : "%d\n", dist[c-1]); 
	return 0;
}

