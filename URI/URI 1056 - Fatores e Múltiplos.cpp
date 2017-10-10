//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1056

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#include <bitset>
#include <stdlib.h>

#define INF 1000000000
#define MAX_V 205

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
int ct; int n, m;
int pairs[2][105];

int res[MAX_V][MAX_V], mf, f, s, t;                     
vi p;

void augment(int v, int minEdge) {    
	if (v == s){
		f = minEdge; 
		return; 
	}else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v])); 
		res[p[v]][v] -= f; 
		res[v][p[v]] += f;
	}      
}

void make_graph(int u, int v, int value = 1){
	AdjList[s].push_back(u);
	AdjList[v].push_back(t);
			
	res[s][u] = 1;
	res[v][t] = 1;
	
	AdjList[u].push_back(v);
	AdjList[v].push_back(u);
	res[u][v] += value;
}

int main(int argc, char **argv)
{
	scanf("%d", &ct);
	for(int q = 1; q <= ct; q++){
		memset(res, 0, sizeof res);
		AdjList.assign(205, vi());
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> pairs[0][i];
		}
		cin >> m;
		for(int i = 1; i <= m; i++){
			cin >> pairs[1][i];
		}
		s = 0; t = n + m+1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				//printf("to pegando %d e %d\n", pairs[0][i], pairs[1][j]);
				if(pairs[0][i] != 0 && (pairs[1][j] % pairs[0][i] == 0)){
					make_graph(i, j + n);
				}else if(pairs[0][i] == pairs[1][j] && pairs[0][i] == 0){
					make_graph(i, j + n);
				}
			}
		}
		mf = 0;
		while (1){
			f = 0;
			bitset<MAX_V> vis; vis[s] = true;           
			queue<int> q; q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == t) break;
				for (int j = 0; j < (int)AdjList[u].size(); j++) {  
					int v = AdjList[u][j];
					if (res[u][v] > 0 && !vis[v])
					vis[v] = true, q.push(v), p[v] = u;
				}
			}
			augment(t, INF);
			if (f == 0) break;
			mf += f;
		}
		printf("Case %d: %d\n", q, mf);
		
	}
	return 0;
}

