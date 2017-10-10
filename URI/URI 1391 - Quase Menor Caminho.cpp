//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1391
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define INF 1000000000

int n, m;
int s, t;
vector<vii> AdjList, AdjList2;
vi dist_source, dist_sink;
int AdjMat[505][505];

void dijkstra(vector<vii> &AdjListx, vector<int> &dist, int source){
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  dist.assign(n, INF); pq.push(ii(0, source));
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

bool isInSSSP(int u, int v){
  return (dist_source[u] + AdjMat[u][v] + dist_sink[v]) == dist_source[t];
}

int main(){
  while(scanf("%d %d", &n, &m) && (n || m)){
    //pai_source.assign(n, 0); pai_sink.assign(n, 0);
    scanf("%d %d", &s, &t);
    AdjList.assign(n, vii());
    AdjList2.assign(n, vii());
    vi disk(n, INF);
    for(int i = 0; i < m; i++){
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      AdjMat[u][v] = w;
      AdjList[u].push_back(ii(v, w));
      AdjList2[v].push_back(ii(u, w));
    }
    dijkstra(AdjList, dist_source, s); dijkstra(AdjList2, dist_sink, t);
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    vi dist(n, INF); pq.push(ii(0, s));
    dist[s] = 0;
    while(!pq.empty()){
      ii front = pq.top(); pq.pop();
      int u = front.second, d = front.first;
      if(d > dist[u]) continue;
      for(int j = 0; j < (int) AdjList[u].size(); j++){
        ii v = AdjList[u][j];
        if(dist[u] + v.second < dist[v.first] && !isInSSSP(u, v.first)){
          dist[v.first] = dist[u] + v.second;
          pq.push(ii(dist[v.first], v.first));
        }
      }      
    }
    printf(dist[t] == INF ? "-1\n" : "%d\n", dist[t]);
  } 
  return 0;
}
