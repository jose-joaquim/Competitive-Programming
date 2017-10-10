//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1592
#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000000

int n, m, k;
vector<vii> AdjList;

int main(){
  int cs; scanf("%d", &cs);
  while(cs--){
    scanf("%d %d %d", &n, &m, &k);
    AdjList.assign(n, vii());
    for(int i = 0; i < m; i++){
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      AdjList[u].push_back(ii(v, w));
    }
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    pq.push(iii(1, ii(0, 0))); vi dist(n, INF);
    while(!pq.empty()){
      iii front = pq.top(); pq.pop();
      ii f = front.second; int u = f.second, d = f.first;
      int cities = front.first;
      if(d < dist[u]){
        dist[u] = d;
        for(int j = 0; j < (int) AdjList[u].size(); j++){
          ii v = AdjList[u][j];
          if(cities + 1 <= k){
            pq.push(iii(cities + 1, ii(dist[u] + v.second, v.first)));
          }
        }
      }
    }
    printf((dist[n-1] == INF) ? "-1\n" : "%d\n", dist[n-1]);
  }
  return 0;
}
