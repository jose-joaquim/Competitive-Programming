//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1209
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m, k;
vector<vi> AdjList;
int grau[1001];
int blocked[1001];

bool remove(){
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    if(!blocked[i] && grau[i] < k){
      blocked[i] = true; cnt++;
      for(int j = 0; j < (int) AdjList[i].size(); j++){
        grau[AdjList[i][j]]--;
      }
    }
  }
  return cnt > 0;
}

int main(){
  while(scanf("%d %d %d", &n, &m, &k) != EOF){
    memset(grau, 0, sizeof grau);
    memset(blocked, 0, sizeof blocked);
    AdjList.assign(n + 1, vi());
    for(int i = 0; i < m; i++){
      int u, v; scanf("%d %d", &u, &v);
      grau[u]++, grau[v]++;
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
    }
    while(remove());
    bool hasSomeone = false;
    vi ans;
    for(int i = 1; i <= n; i++){
      if(!blocked[i]){
        ans.push_back(i);
      }
    }
    if(ans.empty()) puts("0");
    else{
      printf("%d", ans[0]);
      for(int i = 1; i < (int) ans.size(); i++){
        printf(" %d", ans[i]);
      }
      puts("");
    }
  }
  return 0;
}
