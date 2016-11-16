/*
esse grafo é implícito
você não precisa gerar explicitamente todos os vértices
basicamente, coloque o número A na fila
todo passo da BFS
você tenta mandar A para as duas direções:
B1 = A + 1 
B2 = INVERSE(A)
Mas você precisa checar se eles já foram visitados
Mas isso é facilmente contornado se você usar um Map (ou um Set)
A complexidade disso? O(10000) (Ora..., só tem 10000 números)
A complexidade da BFS é O(V+E)... Como E = V * 2 (Cada vértice tem 2 arestas), fica O(V) mesmo
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

int invert(int u) {
  int reverse = 0, rmn = 0;
  while(u != 0) {
    rmn = u % 10;
    reverse = reverse * 10 + rmn;
    u /= 10;
  }
  return reverse;
}

ii edges(int u) {
  return ii(u+1, invert(u));
}

int bfs(int a, int b) {
  int dist[100000];
  memset(dist, -1, sizeof dist);
  
  queue<int> qe; qe.push(a);
  dist[a] = 0;
  while (!qe.empty()) {
    int u = qe.front(); qe.pop();
    
    if (u == b) {
      return dist[u];
    }
    
    ii ed = edges(u);
    
    int v1 = ed.first;
    if (dist[v1] == -1) {
       dist[v1] = dist[u] + 1;
       qe.push(v1);
    }
    
    int v2 = ed.second;
    if (dist[v2] == -1) {
      dist[v2] = dist[u] + 1;
      qe.push(v2);
    }
  }
  
  return dist[b];
}

int main() {
  int t; scanf("%d", &t);
  while (t--) {
    int a, b; scanf("%d %d", &a, &b);
    int ans = bfs(a, b);
    printf("%d\n", ans);
  }
}
