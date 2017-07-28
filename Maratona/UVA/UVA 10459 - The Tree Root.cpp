//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1400
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int n, diameter;
vector<vi> adj;
vi centers, level, degree, dfs_num;
set<int> worst;

#define VISITED 1
#define UNVISITED -1

int getCenters(){
  
  queue<int> q;
  int maxlevel = 0;
  for(int i = 1; i <= n; i++){
    if(degree[i] == 1){
      q.push(i);
    }
  }
  
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int i = 0; i < (int) adj[u].size(); i++){
      int v = adj[u][i];
      if(--degree[v] == 1){
        q.push(v);
        level[v] = level[u] + 1;
        maxlevel = max(maxlevel, level[v]);
      }
    }
  }

  for(int i = 1; i <= n; i++){
    if(level[i] == maxlevel){
      centers.push_back(i);
    }
  }
  
  diameter = (maxlevel*2 + centers.size() - 1);

  return (diameter + 1)/2;
}

inline void read(){
  adj.assign(n + 1, vi());
  degree.assign(n + 1, 0);
  level.assign(n + 1, 0);
  worst.clear();
  centers.clear();
  for(int i = 1; i <= n; i++){
    int q; scanf("%d", &q);
    for(int j = 0; j < q; j++){
      int v; scanf("%d", &v);
      adj[i].push_back(v);
      degree[v]++;
    }
  }
}

void dfs(int u, int length){
  dfs_num[u] = length;
  for(int j = 0; j < (int) adj[u].size(); j++){
    int v = adj[u][j];
    if(dfs_num[v] == UNVISITED){
      dfs(v, length + 1);
    }
  }
}


int main(){
  while(scanf("%d", &n) != EOF){
    read();
    int mx = getCenters();
    printf("Best Roots  :");
    for(int i = 0; i < (int) centers.size(); i++){
      printf(" %d", centers[i]);
      dfs_num.assign(n + 1, UNVISITED);
      dfs(centers[i], 0);
      for(int j = 1; j <= n; j++){
        if(dfs_num[j] == mx) worst.insert(j);
      }
    }
    printf("\nWorst Roots :");
    for(auto &x : worst){
      printf(" %d", x);
    }
    puts("");
  }
  return 0;
}
