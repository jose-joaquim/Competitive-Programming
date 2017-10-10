//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: http://olimpiada.ic.unicamp.br/pratique/programacao/nivel2/2011f1p2_cartografico

#include <bits/stdc++.h>

using namespace std;

#define UNVISITED -1
#define VISITED 1

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num;
int n, last, pos_last;

void dfs(int u, int length = 0){
  dfs_num[u] = length;
  last = max(last, dfs_num[u]);
  if(length > last){
    pos_last = u;
    last = length;
  }
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(dfs_num[v] == UNVISITED){
      dfs(v, length + 1);
    }
  }
}

int main(){
  scanf("%d", &n);
  AdjList.assign(n, vi());
  last = pos_last = -1;
  for(int i = 1; i < n; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    AdjList[u-1].push_back(v-1);
    AdjList[v-1].push_back(u-1);
  }
  dfs_num.assign(n, UNVISITED);
  dfs(0);
  // printf("vertice mais longe que visitei foi %d\n", pos_last);
  dfs_num.assign(n, UNVISITED);
  dfs(pos_last);
  cout << last << endl; 
  return 0;
}
