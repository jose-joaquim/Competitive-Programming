//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1271
#include <bits/stdc++.h>

using namespace std;

#define MAX_V 210
#define INF 1000000000

typedef vector<int> vi;

vector<vi> AdjList;
int N, M, B, D;
int res[MAX_V][MAX_V], mf, f, s, t;
vi p;

void augment(int v, int minEdge) {
  if (v == s) { f = minEdge; return; }
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
	res[p[v]][v] -= f; res[v][p[v]] += f; }
}

int main(){
  while(scanf("%d", &N) != EOF){
	s = 0; t = MAX_V - 1;
	memset(res, 0, sizeof res);
	AdjList.assign(MAX_V, vi());
	for(int i = 1; i <= N; i++){
	  int cap; scanf("%d", &cap);
	  AdjList[2*i].push_back(2*i - 1);
	  AdjList[2*i - 1].push_back(2*i);
	  res[2*i - 1][2*i] = cap;
	}
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
	  int u, v, x;
	  scanf("%d %d %d", &u, &v, &x);
	  AdjList[2*u].push_back(2*v - 1);
	  AdjList[2*v - 1].push_back(2*u);
	  res[2*u][2*v - 1] += x;
	}
	scanf("%d %d", &B, &D);
	for(int i = 0; i < B; i++){
	  int sub; scanf("%d", &sub);
	  AdjList[s].push_back(2*sub - 1);
	  res[s][2*sub - 1] = INF;
	}
	for(int i = 0; i < D; i++){
	  int tub; scanf("%d", &tub);
	  AdjList[2*tub].push_back(t);
	  res[2*tub][t] = INF;
	}

	mf = 0;
	while (1) {
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
	printf("%d\n", mf);
  }
  return 0;
}
