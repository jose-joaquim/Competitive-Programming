#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <map>
#include <bitset>
#include <queue>

#define MAX_V 50
#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int N, M, G;
int res[MAX_V][MAX_V], s, t, mf, f;
vector<vi> AdjList;
map<ii, bool> al;
vi p;

void augment(int v, int minEdge) {
  if (v == s) { f = minEdge; return; } 
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); 
                         res[p[v]][v] -= f; res[v][p[v]] += f; }      
}

int main(){
  int cs = 0;
  while(scanf("%d %d %d", &N, &M, &G) && (N || M || G)){
    al.clear();
    printf("CASO DE TESTE %d\n", ++cs);
    memset(res, 0, sizeof res);
    s = 41, t = 44;
    AdjList.assign(MAX_V, vi());
    mf = 0;
    for(int i = 0; i < N; i++){
      AdjList[s].push_back(i);
      res[s][i] = INF;
      AdjList[i].push_back(t);
      res[i][t] = 1;
    }
    //puts("oi");
    for(int i = 0; i < G; i++){
      int I, J; char C;
      scanf("%d %c %d", &I, &C, &J);
      if(!al.count(ii(I, J))){
	AdjList[I].push_back(J);
	AdjList[J].push_back(I);
	al[ii(I, J)] = true;
      }
      if(C == '<'){
	res[J][I] += 2;
      }else if(C == '>'){
	res[I][J] += 2;
      }else{//C == '='
	res[J][I] += 1;
	res[I][J] += 1;
      }
    }
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
    printf("mf foi %d e M eh %d\n", mf, M);
    puts(mf > (M*N - G) ? "Y" : "N");
  }
}
