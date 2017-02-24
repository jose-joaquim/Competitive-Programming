//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1227
#include <queue>
#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define VISITED 1
#define UNVISITED -1
#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int n, a, b, c, w, distBC;

vector<vi> AdjList;
vi pathBC;
bool stop;

void bfs(int s){
  vector<int> ini; ini.push_back(s);
  queue<pair<int, vector<int> > > q; q.push(make_pair(s, ini));
  vi dist(n + 1, INF); dist[s] = 0;
  bool ccc = true;
  while(!q.empty() & ccc){
    pair<int, vector<int> > top = q.front(); q.pop();
    int u = top.first;
    if(u == c){
      pathBC = top.second;
      distBC = (int) top.second.size() - 1;
      ccc = false;
    }
    for(int j = 0; j < (int) AdjList[u].size() && ccc; j++){
      int v = AdjList[u][j];
      if(dist[v] == INF){
        dist[v] = dist[u] + 1;
        vector<int> nv(top.second);
        nv.push_back(v);
        q.push(make_pair(v, nv));
      }
    }
  }
}

int bfs2(int s){
  queue<int> q; q.push(s);
  vi dist(n + 1, INF); dist[s] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    if(binary_search(pathBC.begin(), pathBC.end(), u)){
      return u;
    }
    for(int j = 0; j < (int) AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if(dist[v] == INF){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return -1;
}

int main(){
  while(scanf("%d %d %d %d", &n, &a, &b, &c) != EOF){
    AdjList.assign(n + 1, vi());
    stop = false;
    distBC = 0;
    for(int i = 0; i < n - 1; i++){
      int u, v; scanf("%d %d", &u, &v);
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
    }
    bfs(b);
    sort(pathBC.begin(), pathBC.end());
    int w = bfs2(a);
    queue<int> q; q.push(w);
    vi dist(n + 1, INF); dist[w] = 0;
    while(!q.empty()){
      int u = q.front(); q.pop();      
      for(int j = 0; j < (int) AdjList[u].size(); j++){
        int v = AdjList[u][j];
        if(dist[v] == INF){
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    printf("%.6lf\n", 1.0 - (dist[b]*1.0)/(distBC*1.0));
  }
  return 0;
}
