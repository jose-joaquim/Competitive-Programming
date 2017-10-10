//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1208
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vi match;
bitset<2048> vis;
int n, m;

int Aug(int l) { 
  if (vis[l]) return 0;
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;                           
    }
  }
  return 0;                                             
}

int main(){
  while(scanf("%d %d", &n, &m) != EOF){
    AdjList.assign(2 * n, vi());
    for(int i = 0; i < m; i++){
      int u, v; scanf("%d %d", &u, &v);
      u--, v--;
      AdjList[u].push_back(n + v);
      //AdjList[v].push_back(n + u);
    }

    int MCBM = 0;
    match.assign(2 * n, -1);
    for(int i = 0; i < n; i++){
      vis.reset();
      MCBM += Aug(i);
    }

    printf("%d\n", n - MCBM);
  }
  return 0;
}
