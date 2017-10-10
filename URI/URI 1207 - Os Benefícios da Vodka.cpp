//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1207
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXV = 1200;
const int MAXE = 1200;
const int INF = 1000000000;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, s, t, all;
int res[MAXV][MAXV];
int visited[MAXV], dist[MAXV];
vector<vii> adj;

bool bfs(int source, int sink){
  queue<int> q;
  for(int i = 0; i < MAXV; i++) dist[i] = INF;
  q.push(source);
  dist[source] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int j = 0; j < (int) adj[u].size(); j++){
      ii v = adj[u][j];
      if(res[v.first][u] < v.second && dist[v.first] == INF){
        dist[v.first] = dist[u] + 1;
        q.push(v.first);
      }
    }
  }
  return dist[sink] != INF;
}

int augment(int u, int minflow){
  if(u == t){
    return minflow;
  }
  for(int j = 0; j < (int) adj[u].size(); j++){
    ii v = adj[u][j];
    if((dist[v.first] == dist[u] + 1) && res[v.first][u] < v.second){
      int curr = min(minflow, v.second - res[v.first][u]);
      int temp = augment(v.first, curr);
      if(temp){
        res[v.first][u] += temp;
        res[u][v.first] -= temp;
        return temp;
      }
    }
  }
  return 0;
}

int dinic(int source, int sink){
  int flow = 0;
  while(bfs(source, sink)){
    while(int f = augment(source, INF)){
      flow += f;
    }
  }
  return flow;
}

void makeGraph(){
  memset(res, 0, sizeof res);
  s = 1, t = n + m + 2;
  all = 0;
  adj.assign(n + m + 3, vii());
  for(int i = 1; i <= n; i++){
    int qw; scanf("%d", &qw);
    adj[m + i + 1].push_back(ii(t, qw));
    res[m + i + 1][t] = qw;
    res[t][m + i + 1] = 0;
  }
  
  int arr[m];
  for(int i = 0; i < m; i++)
    scanf("%d", &arr[i]);

  for(int i = 1; i <= m; i++){
    int price; scanf("%d", &price);
    all += price;
    adj[s].push_back(ii(s + i, price));
    res[s][s + i] = price;
    res[s + i][s] = 0;
    for(int j = 0; j < arr[i - 1]; j++){
      int x; scanf("%d", &x);
      adj[s + i].push_back(ii(m + x + 1, INF));
      adj[m + x + 1].push_back(ii(s + i, INF));
      res[s + i][m + x + 1] = INF;
      res[m + x + 1][s + i] = 0;
    }
  }
}


int main(){
  while(scanf("%d %d", &n, &m) != EOF){
    makeGraph();
    int fl = dinic(1, n + m + 2);
    printf("%d\n", all - fl);
  }
  return 0;
}
