//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2375
#include <cstdio>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;

#define MAX_V 100
#define INF 1000000000

int res[MAX_V][MAX_V], mf, f, s, t;
vi p;
int X, Y, P;
char grid[MAX_V][MAX_V];

void augment(int v, int minEdge) {
  if (v == s) { f = minEdge; return; } 
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
	res[p[v]][v] -= f; res[v][p[v]] += f; }
}

int main(){
  while(scanf("%d %d %d", &X, &Y, &P) != EOF){
	cin.ignore();
	s = 0; t = MAX_V-1;
	memset(res, 0, sizeof res);
    for(int i = 0; i < X; i++){
	  string linha;
	  getline(cin, linha);
	  for(int j = 0; j < Y; j++){
	    grid[i][j] = linha[j];
	  }
	}

	mf = 0; 
	while (1) {
	  f = 0;
	  vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
	  p.assign(MAX_V, -1);
	  while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int v = 0; v < MAX_V; v++)
		  if (res[u][v] > 0 && dist[v] == INF)
			dist[v] = dist[u] + 1, q.push(v), p[v] = u;
	  }
	  augment(t, INF);     
	  if (f == 0) break;   
	  mf += f;            
	}

	printf("%d\n", mf);         
  }
  return 0;
}
