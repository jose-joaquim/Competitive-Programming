//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3198
#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList, AdjList2;
vi dist_source, dist_sink;

int N, M, s, t, p;

void dijkstra(vector<vii> &AdjListx, vector<int> &dist, int source){
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  dist.assign(N + 1, INF); pq.push(ii(0, source));
  dist[source] = 0;
  while(!pq.empty()){
    ii front = pq.top(); pq.pop();
    int u = front.second, d = front.first;
    if(d > dist[u]) continue;
    for(int j = 0; j < (int) AdjListx[u].size(); j++){
      ii v = AdjListx[u][j];
      if(dist[u] + v.second < dist[v.first]){
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first], v.first));
      }
    }      
  }
}

bool notExceed(int x, int g, int w){
  return (dist_source[x] + w + dist_sink[g]) <= p; }

int main(){
  int T; scanf("%d", &T);
  while(T--){
    scanf("%d %d %d %d %d", &N, &M, &s, &t, &p);
    AdjList.assign(N + 1, vii());
    AdjList2.assign(N + 1, vii());
    for(int i = 0; i < M; i++){
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      AdjList[u].push_back(ii(v, c));
      AdjList2[v].push_back(ii(u, c));
    }
    dist_source.assign(N + 1, INF); dist_sink.assign(N + 1, INF);
    dijkstra(AdjList, dist_source, s); dijkstra(AdjList2, dist_sink, t);
    vi dist(N + 1, INF); dist[s] = 0;
    priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0, s));
    int ans = -1;
    while(!pq.empty()){
      ii front = pq.top(); pq.pop();
      int d = front.first, u = front.second;
      if(d > dist[u]) continue;
      for(int j = 0; j < (int) AdjList[u].size(); j++){
        ii v = AdjList[u][j];
        int w = dist[u] + v.second;
        if(w < dist[v.first]){
          dist[v.first] = w;
          pq.push(ii(dist[v.first], v.first));
        }
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < (int) AdjList[i].size(); j++){
        if(notExceed(i, AdjList[i][j].first, AdjList[i][j].second)){
          ans = max(ans, AdjList[i][j].second);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
