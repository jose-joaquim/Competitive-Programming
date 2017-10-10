//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2131
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef vector<int> vi;

int n, m;

int main(){
  int cs = 0;
  bool brk = false;
  while(scanf("%d %d", &n, &m) != EOF){
    if(brk) printf("\n"); else brk = true;
    printf("Instancia %d\n", ++cs);
    vector<vi> AdjList(n + 1, vi());
    for(int i = 0; i < m; i++){
      int u, v; scanf("%d %d", &u, &v);
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
    }
    queue<int> q; q.push(1);
    vi colors(n + 1, 1000000000);
    colors[1] = 0;
    bool isBipartite = true;
    while(!q.empty() & isBipartite){
      int u = q.front(); q.pop();
      for(int j = 0; j < (int) AdjList[u].size(); j++){
        int v = AdjList[u][j];
        if(colors[v] == 1000000000){
          colors[v] = 1 - colors[u];
          q.push(v);
        }else if(colors[u] == colors[v]){
          //puts("ASdas");
          isBipartite = false;
        }
      }
    }
    printf("%s\n", isBipartite ? "sim" : "nao");
  }
  puts("");
  return 0;
}
