//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1454
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = 1000000000;
const int MAXV = 101;

int n, m;
int AdjMat[MAXV][MAXV];
vector<vi> AdjList;

int main(){
  bool brk = false; int cs = 0;
  while(scanf("%d %d", &n, &m) && n){
    if(brk) puts(""); else brk = true;
    printf("Instancia %d\n", ++cs);
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) AdjMat[i][j] = INF;

    for(int i = 0; i < m; i++){
      int u, v, w; scanf("%d %d %d", &u, &v, &w);
      AdjMat[u][v] = min(AdjMat[u][v], w);
      AdjMat[v][u] = min(AdjMat[v][u], w);
    }
    
    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          AdjMat[i][j] = min(max(AdjMat[i][k], AdjMat[k][j]), AdjMat[i][j]);

    int q; scanf("%d", &q);
    while(q--){
      int u, v; scanf("%d %d", &u, &v);
      printf("%d\n", (u == v) ? 0 : AdjMat[u][v]);
    }
  }
  puts("");
  return 0;
}
