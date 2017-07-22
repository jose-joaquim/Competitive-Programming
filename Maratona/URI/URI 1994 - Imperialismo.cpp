//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1994
#include <queue>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
vector<vi> AdjList;
vi dfs_num;

const int INF = 1000000000;
const int UNVISITED = -1;

void dfs(int u, int length){
  dfs_num[u] = length;
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(dfs_num[v] == UNVISITED){
      dfs(v, length + 1);
    }
  }
}

int getDiameter(){
  int diameter = 0;
  dfs_num.assign(n + 1, UNVISITED);
  dfs(1, 0);
  int x = 0, mx = 0;
  for(int i = 1; i <= n; i++){
    if(dfs_num[i] > mx){
      x = i;
      mx = dfs_num[i];
    }
  }
  //
  dfs_num.assign(n + 1, UNVISITED);
  dfs(x, 0);
  for(int i = 1; i <= n; i++){
    diameter = max(diameter, dfs_num[i]);
  }
  return diameter;
}

int main(){
  while(scanf("%d", &n) && n != -1){
    AdjList.assign(n + 1, vi());
    for(int i = 1; i <= n - 1; i++){
      int u; scanf("%d", &u);
      AdjList[i + 1].push_back(u);
      AdjList[u].push_back(i + 1);
    }
    int ans = getDiameter();
    printf("%d\n", (ans % 2 == 0) ? (ans/2) : (ans/2) + 1);
  }
  return 0;
}
