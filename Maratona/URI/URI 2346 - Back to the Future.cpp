//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2346
#include <iostream>
#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

typedef vector<int> vi;

int n, m, a, b;
set<int> excluidos, vertices;
map<int, set<int> > AdjList;
vi grau;

bool satisfaz(int u){
  return (grau[u] >= a) && (n - grau[u] - 1 >= b);
}

void adjacentes(int u){
  for(auto p1 = AdjList[u].begin(); p1 != AdjList[u].end(); p1++){
    grau[*p1]--;
    AdjList[*p1].erase(u);
  }
}

int bfs(){
  queue<int> q; int ret = 0;
  int aux = n, ct = 0;
  for(auto p2 = vertices.begin(); p2 != vertices.end(); p2++){
    if(!satisfaz(*p2) && excluidos.find(*p2) == excluidos.end()){
      ct++;
      adjacentes(*p2);
      q.push(*p2);
      ret++;
      n--;
      excluidos.insert(*p2);
    }
  }
  while(!q.empty()){
    int u = q.front(); q.pop();
    vertices.erase(u);
    for(auto p1 = AdjList[u].begin(); p1 != AdjList[u].end(); p1++){
      int v = *p1;
      AdjList[v].erase(u);
      if(!satisfaz(v) && excluidos.find(v) == excluidos.end()){
        adjacentes(v);
        ret++;
        n--;
        q.push(v); 
        excluidos.insert(v);
      }
    }
  }
  return ret;
}

int main(){
  while(scanf("%d %d %d %d", &n, &m, &a, &b) != EOF){
    grau.assign(n + 1, 0);
    excluidos.clear();
    AdjList.clear();
    vertices.clear();

    for(int i = 1; i <= n; i++) vertices.insert(i);
    for(int i = 0; i < m; i++){
      int u, v; scanf("%d %d", &u, &v);
      AdjList[u].insert(v);
      AdjList[v].insert(u);
      grau[u]++, grau[v]++;
    }

    while(bfs());
    printf("%d\n", n);
  }
  return 0;
}
