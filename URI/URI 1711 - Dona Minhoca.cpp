//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1711


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <stack>

#define INF 1000000000
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 2

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dfs_num, dfs_low, dfs_parent, dist;
int s, t, q, dfsNumberCount, minhoca, vez;
int length_cycle[10010];

map<ii, bool> my;
vector<ii> vet;

void bridges(int u){
  dfs_num[u] = dfs_low[u] = dfsNumberCount++;
  for(int j = 0; j < (int) AdjList[u].size(); j++){
    ii v = AdjList[u][j];
    if(dfs_num[v.first] == UNVISITED){
      dfs_parent[v.first] = u;
      bridges(v.first);
      if(dfs_low[v.first] > dfs_low[u]){
        my[ii(u, v.first)] = true;
        my[ii(v.first, u)] = true;
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }else if(v.first != dfs_parent[u]){
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
  }
}

stack<int> pilha;

void graphCheck(int u, int length){
  dfs_num[u] = EXPLORED;
  for(int j = 0; j < (int) AdjList[u].size(); j++){
    ii v = AdjList[u][j];
    if(dfs_num[v.first] == UNVISITED && !my[ii(u, v.first)]){
      dfs_parent[v.first] = u;
      pilha.push(v.first);
      graphCheck(v.first, length + v.second);
    }else if(dfs_num[v.first] == EXPLORED){
      if(!(v.first == dfs_parent[u])){
        int u = -1;
        while(u != vez){					
          u = pilha.top();
          length_cycle[u] = length + v.second;
          pilha.pop();
        }
      }
    }
  }
  dfs_num[u] = VISITED;
}

int main(int argc, char **argv)
{
  while(scanf("%d %d", &s, &t) != EOF){
    AdjList.assign(s, vii());
    my.clear();
    for(int i = 0; i < t; i++){
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      AdjList[u-1].push_back(ii(v-1, w));
      AdjList[v-1].push_back(ii(u-1, w));
      my[ii(u-1, v-1)] = false;
      my[ii(v-1, u-1)] = false;
    }
    scanf("%d", &q);
    dfsNumberCount = 0; dfs_parent.assign(s, 0); dfs_num.assign(s, UNVISITED);
    dfs_low.assign(s, 0);
    for(int j = 0; j < s; j++){
      if(dfs_num[j] == UNVISITED){
        bridges(j);
      }
    }
    dfs_parent.assign(s, 0); dfs_num.assign(s, UNVISITED);
    for(int j = 0; j < s; j++){
      if(dfs_num[j] == UNVISITED){
        vez = j;
        pilha.push(j);
        graphCheck(j, 0);
      }
    }
    for(int i = 0; i < q; i++){
      int ini;
      scanf("%d %d", &ini, &minhoca);
      dist.assign(s, INF);
      priority_queue<ii, vector<ii>, greater<ii> > pq;
      pq.push(ii(0, ini-1)); dist[ini-1] = 0;
      while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first; int u = front.second;
        if(d > dist[u]) continue;
        for(int j = 0; j < (int) AdjList[u].size(); j++){
          ii v = AdjList[u][j];
          if(dist[u] + v.second < dist[v.first]){
            dist[v.first] = dist[u] + v.second;
            pq.push(ii(dist[v.first], v.first));
          }
        }			
      }
      dfs_num.assign(s, UNVISITED); dfs_parent.assign(s, 0);
      int ans = INF;
      for(int j = 0; j < s; j++){
        if(length_cycle[j] >= minhoca){
          ans = min(ans, 2*dist[j] + length_cycle[j]);
        }
      }
      printf(ans == INF ? "-1\n" : "%d\n", ans);
    }
  }
  return 0;
}
