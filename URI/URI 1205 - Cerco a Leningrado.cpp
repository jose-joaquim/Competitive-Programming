//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1205
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1000000000;
int n, m, k, s, t;
double p;
vector<vi> AdjList;
vi soldiers, dist;

void readInput(){
  AdjList.assign(n + 1, vi());
  soldiers.assign(n + 1, 0);
  for(int i = 0; i < m; i++){
    int u, v; scanf("%d %d", &u, &v);
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
  }
  int a; scanf("%d", &a);
  for(int i = 0; i < a; i++){
    int q; scanf("%d", &q);
    soldiers[q]++;
  }
  scanf("%d %d", &s, &t);
}

bool dijkstra(){
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  dist.assign(n + 1, INF);
  pq.push(ii(soldiers[s], s)); dist[s] = soldiers[s];
  
  while(!pq.empty()){
    ii front = pq.top(); pq.pop();
    int d = front.first, u = front.second;
    if(dist[u] > d) continue;
    for(int j = 0; j < (int) AdjList[u].size(); j++){
      int v = AdjList[u][j];
      if(dist[v] > d + soldiers[v]){
        dist[v] = d + soldiers[v];
        pq.push(ii(dist[v], v));
      }
    }
  }

  return dist[t] != INF;
}

int main(){
  while(scanf("%d %d %d %lf", &n, &m, &k, &p) != EOF){
    readInput();
    if(!dijkstra() || dist[t] > k){
      printf("%.3lf\n", 0.000);
    }else{
      printf("%.3lf\n", pow(p, dist[t]));
    }
  }
  return 0;
}
