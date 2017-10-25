//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=929
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef vector<int> vi;

const int MAXN = 100005;

int n;
vector<vi> adj;
int dp[MAXN];//[MAXL];

int solve(int u){
  if(adj[u].size() == 0)
    return 1;

  if(dp[u] != -1)
    return dp[u];

  int result = 0;

  for(int i = 0; i < (int) adj[u].size(); i++){
    result += solve(adj[u][i]);
  }

  return dp[u] = result;
}

int main(){
  bool bkr = false;
  while(scanf("%d", &n) != EOF){
    memset(dp, -1, sizeof dp);
    if(bkr) puts(""); else bkr = true;
    adj.assign(n + 1, vi());
    for(int i = 0; i < n; i++){
      int q; scanf("%d", &q);
      for(int j = 0; j < q; j++){
        int u; scanf("%d", &u);
        adj[i].push_back(u);
      }
    }
    printf("%d\n", solve(0));
  }
  return 0;
}
