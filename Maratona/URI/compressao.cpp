#include <bits/stdc++.h>

using namespace std;

#define UNVISITED -1
#define VISITED 1

typedef vector<int> vi;

vi dfs_num, dfs_parent, dfs_low, visited, S;
map<int, vi> vet_SCC;
vector<vi> AdjList;
int n, dfsNumberCount, nSCC;

void tarjanSCC(int u){
  dfs_num[u] = dfs_low[u] = dfsNumberCount++;
  S.push_back(u); visited[u] = true;
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(dfs_num[v] == UNVISITED){
      tarjanSCC(v);
    }
    if(visited[v]){
      dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }
  }

  if(dfs_low[u] == dfs_num[u]){
    printf("nSCC %d:", ++nSCC);
    while(true){
      int v = S.back(); S.pop_back(); visited[v] = false;
      printf(" %d", v);
      vet_SCC[nSCC].push_back(v);
      if(u == v) break;
    }
    puts("");
  }  
}

int main(){
  while(scanf("%d", &n) != EOF){
    dfs_num.assign(n+1, UNVISITED);
    dfs_low.assign(n+1, 0);
    visited.assign(n+1, false);
    nSCC = dfsNumberCount = 0;
    AdjList.assign(n+1, vi());
    for(int u = 1; u <= n; u++){
      int v; cin >> v;
      AdjList[u].push_back(v);
    }
    //identificar os SCC
    for(int i = 1; i <= n; i++){
      if(dfs_num[i] == UNVISITED){
	tarjanSCC(i);
      }
    }
    //componentes com tamanho maior do que um devem ser comprimidos
    //dados dois vértices, se estiverem em componentes diferentes, então -1
    //mesmo componente, fabs(dist[raiz] - dist[u]) + fabs(dist[raiz] - dist[v])
    //componentes diferentes, aplica LCA(comp(u), comp(v)) + dist dentro dos componentes
    printf("CABOU || \n");
  }
  return 0;
}
