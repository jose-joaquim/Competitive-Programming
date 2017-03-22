//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2468
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

long long n;
vector<vi> AdjList;
vector<int> dfs_num;
int cont;

#define VISITED 1
#define UNVISITED -1

int dfs(int u){
  dfs_num[u] = VISITED;
  int ret = 0;
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(dfs_num[v] == UNVISITED){
      ret += 1 + dfs(v);
    }
  }
  return ret;
}

int main(){
  int ans = 0;
  scanf("%lld", &n);
  AdjList.assign(n + 1, vi());
  dfs_num.assign(n + 1, UNVISITED);
  for(int i = 1; i < n; i++){
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    if(!w){
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
    }
  }
  long long complementar = 0;
  vector<int> tamanhos;
  for(int i = 1; i <= n; i++){
    if(dfs_num[i] == UNVISITED){
      int ret = dfs(i) + 1;
      tamanhos.push_back(ret);
    }
  }
  for(auto c : tamanhos){
    complementar += c*(c - 1)/2;
  }
  printf("%lld\n", n*(n-1)/2 - complementar);
  return 0;
}
