//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2576
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1000000000;

int c, s, a, b;
vector<vi> AdjList;
vi pai;
map<int, set<int> > vertexX;

int dijkstra(int source, int t){
  vi dist(c + 1, INF); dist[source] = 0;
  priority_queue<ii, vii, greater<ii> > pq;
  pq.push(ii(0, source));
  pai.assign(c + 1, 0);
  while(!pq.empty()){
    ii front = pq.top(); pq.pop();
    int u = front.second, d = front.first;
    if(d > dist[u]) continue;
    for(int j = 0; j < (int) AdjList[u].size(); j++){
      int v = AdjList[u][j];
      int next = 0;
      if(vertexX[u].find(v) == vertexX[u].end()){
        next = 1;
      }
      if(dist[u] + next < dist[v]){
        dist[v] = dist[u] + next;
        pq.push(ii(dist[v], v));
      }
    }
  }
  return dist[t];
}

int main(){
  scanf("%d %d %d %d", &c, &s, &a, &b);
  AdjList.assign(c + 1, vi());
  for(int i = 0; i < s; i++){
    int u, v; scanf("%d %d", &u, &v);
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
    vertexX[u].insert(v);
  }

  int A1 = dijkstra(a, b);
  int B1 = dijkstra(b, a);
  
  if(A1 < B1) printf("Bibi: %d\n", A1);
  else if(B1 < A1) printf("Bibika: %d\n", B1);
  else puts("Bibibibika");
  return 0;
}
