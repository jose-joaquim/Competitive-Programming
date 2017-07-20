//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2103
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1000000000;
const int MOD = 1300031;
const int MAXV = 10001;

int n, ans;
vector<vii> AdjList;
vi dfs_num;

int dfs(int x, int u){
  int qtd = 1, howMany;
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    ii v = AdjList[u][i];
    if(x != v.first){
      howMany = dfs(u, v.first);
      ans += howMany * (n - howMany) * v.second;
      ans %= MOD;
      qtd += howMany;      
    }
  }
  return qtd;
}

int main(){
  int T; scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    AdjList.assign(n + 1, vii());
    dfs_num.assign(n + 1, false);
    for(int i = 0; i < n - 1; i++){
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      AdjList[u].push_back(ii(v, w));
      AdjList[v].push_back(ii(u, w));
    }

    ans = 0;
    for(int i = 1; i <= n; i++){
      if((int) AdjList[i].size() == 1){
        dfs(-1, i);
        break;
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
