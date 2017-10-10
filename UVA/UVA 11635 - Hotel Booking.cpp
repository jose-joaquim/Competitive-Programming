//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2682
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int INF = 1000000000;
const int MAXH = 103;
const int MAXV = 10005;

int n, h, m;
vector<int> hotel, rev;//, dist;
vector<vii> AdjList;
int distMat[MAXH][MAXV];
vi dist;

bool dijkstra(int k, int idR){
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  //dist.assign(n + 1, INF);
  //int newV = idH[k];
  for(int i = 0; i < MAXV; i++) distMat[k][i] = INF;
  pq.push(ii(0, idR)); distMat[k][idR] = 0;
  while(!pq.empty()){
    ii front = pq.top(); pq.pop();
    int u = front.second, d = front.first;
    if(d > distMat[k][u]) continue;
    for(int j = 0; j < (int) AdjList[u].size(); j++){
      ii v = AdjList[u][j];
      if(distMat[k][u] + v.second < distMat[k][v.first]){
        distMat[k][v.first] = distMat[k][u] + v.second;
        pq.push(ii(distMat[k][v.first], v.first));
      }
    }
  }
  
  return distMat[k][n] <= 600;
}

inline void allHotel(){
  for(int k = 0; k < (int) hotel.size(); k++){
    dijkstra(k, hotel[k]);
  }
}

int bfs(){
  queue<ii> q;
  bool visited[MAXH];
  memset(visited, false, sizeof visited);
  for(int i = 0; i < (int) hotel.size(); i++){
    if(dist[hotel[i]] <= 600){
      q.push(ii(i, 1));
      visited[i] = true;
    }
  }
  while(!q.empty()){
    ii state = q.front(); q.pop();
    int u = state.first, d = state.second;
  
    if(distMat[u][n] <= 600)
      return d;
    
    for(int i = 0; i < (int) hotel.size(); i++){
      if(distMat[u][hotel[i]] <= 600 && !visited[i]){
        q.push(ii(i, d + 1));
        visited[i] = true;
      }
    }
  }
  return -1;
}

int main(){
  while(scanf("%d", &n) && n){
    AdjList.assign(n + 1, vii());
    hotel.clear();
    scanf("%d", &h);
    for(int i = 1; i <= h; i++){
      int x; scanf("%d", &x);
      hotel.push_back(x);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
      int u, v, w; scanf("%d %d %d", &u, &v, &w);
      AdjList[u].push_back(ii(v, w));
      AdjList[v].push_back(ii(u, w));
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, 1)); dist.assign(n + 1, INF); dist[1] = 0;
    while(!pq.empty()){
      ii front = pq.top(); pq.pop();
      int d = front.first, u = front.second;
      if(d > dist[u]) continue;
      for(int i = 0; i < (int) AdjList[u].size(); i++){
        ii v = AdjList[u][i];
        if(dist[u] + v.second < dist[v.first]){
          dist[v.first] = dist[u] + v.second;
          pq.push(ii(dist[v.first], v.first));
        }
      }
    }

    if(dist[n] <= 600) puts("0");
    else{
      allHotel();
      printf("%d\n", bfs());
    }
  }
  return 0;
}
