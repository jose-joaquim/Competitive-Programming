//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1910


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int o, d, k;

bool can(int u){
	return u >= 1 && u <= 1e5;
}

int main(int argc, char **argv)
{
	while(scanf("%d %d %d", &o, &d, &k) && (o || d || k)){
		//int proi[100000];
		int dist[1000000 + 5];
		//memset(proi, 0, sizeof proi);
		memset(dist, -1, sizeof dist);
		for(int i = 0; i < k; i++){
			int u;
			scanf("%d", &u);
			dist[u] = -2;
		}
		queue<int> q; 
		dist[o] = 0;
		q.push(o);
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(u == d) break;
			int v;
			v = u + 1;
			if(can(v) && dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			v = u - 1;
			if(can(v) && dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			v = u*2;
			if(can(v) && dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			v = u*3;
			if(can(v) && dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			v = u/2;
			if(u % 2 == 0 && can(v) && dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		printf("%d\n", dist[d]);
	}
	return 0;
}

