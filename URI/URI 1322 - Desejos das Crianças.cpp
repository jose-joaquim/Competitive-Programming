//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1322
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define VISITED 1
#define UNVISITED 0
#define EXPLORED 2

int k, w;

map<int, int> grau;
map<int, vi> AdjList;
map<int, int> dfs_num, dfs_parent;
bool ans;

void dfs(int u, int qtd){
  dfs_num[u] = EXPLORED;
  for(int i = 0; i < AdjList[u].size() && ans; i++){
    int v = AdjList[u][i];
    if(dfs_num[v] == UNVISITED){
      dfs_parent[v] = u;
      dfs(v, qtd + 1);
    }else if(dfs_num[v] == EXPLORED){
      if(!(v == dfs_parent[u]) && qtd != k){
        ans = false;
        return;
      }
    }
  }
  dfs_num[u] = VISITED;
}

int main(){
  while(scanf("%d %d", &k, &w) && (k || w)){
    if(w == 0){ puts("Y"); continue; }
    ans = true;
    AdjList.clear(); dfs_num.clear();
    dfs_parent.clear();
    grau.clear();
    map<pair<int, int>, bool> already;
    for(int i = 0; i < w; i++){
      int u, v;
      scanf("%d %d", &u, &v);
      if(already.find(ii(u, v)) != already.end()) continue;
      if(already.find(ii(v, u)) != already.end()) continue;
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
      grau[v]++;
      grau[u]++;
      already[ii(u, v)] = true;
      already[ii(v, u)] = true;
    }
    bool go = true;
    for(auto i = grau.begin(); i != grau.end(); i++){
      if(i->second > 2){
        go = false;
        break;
      }
    }
    if(!go){ puts("N"); continue; }
    for(auto i = AdjList.begin(); i != AdjList.end() && ans; i++){
      if(dfs_num[i->first] == UNVISITED){
        dfs(i->first, 1);
      }
    }
    puts(ans ? "Y" : "N");
  }
  return 0;
}
