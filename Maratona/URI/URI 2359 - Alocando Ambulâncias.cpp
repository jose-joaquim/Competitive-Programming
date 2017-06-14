//Author/Autor: Jos? Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2359

#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1000000000;

int n, m, q;
vector<vii> AdjList;

int main(){
  while(scanf("%d %d %d", &n, &m, &q) != EOF){
    AdjList.assign(n + 2, vii());
    for(int i = 0; i < m; i++){
      int u, v, w; scanf("%d %d %d", &u, &v, &w);
      AdjList[u].push_back(ii(v, w));
      AdjList[v].push_back(ii(u, w));
    }
    for(int i = 0; i < q; i++){
      int u; scanf("%d", &u);
      AdjList[0].push_back(ii(u, 0));
      AdjList[u].push_back(ii(0, 0));
    }
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, 0));
    vi dist(n + 2, INF); dist[0] = 0;
    while(!pq.empty()){
      ii front = pq.top(); pq.pop();
      int u = front.second, d = front.first;
      if(d > dist[u]) continue;
      for(int j = 0; j < (int) AdjList[u].size(); j++){
        ii v = AdjList[u][j];
        int w = dist[u] + v.second;
        if(w < dist[v.first]){
          dist[v.first] = w;
          pq.push(ii(w, v.first));
        }
      }
    }
    int ans = -INF;
    for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);
    printf("%d\n", ans);
  }
  return 0;
}
