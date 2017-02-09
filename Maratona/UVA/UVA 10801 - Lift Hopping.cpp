//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1742
#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, sink;
int speed[6];
vector<vii> AdjList;
vector<vi> adjs;

void make_graph(){
  for(int k = 0; k < n; k++){
    int sz = (int) adjs[k].size(); 
    for(int i = 0; i < sz; i++){
      int u = adjs[k][i];
      for(int j = i + 1; j < sz; j++){
        int v = adjs[k][j];
        AdjList[100*k + u].push_back(ii(100*k + v, (v - u)*speed[k]));
        AdjList[100*k + v].push_back(ii(100*k + u, (v - u)*speed[k]));
      }
    }
  }
  for(int k = 0; k < n; k++){
    int sz = (int) adjs[k].size();
    for(int i = 0; i < sz; i++){
      int look = adjs[k][i];
      for(int j = k + 1; j < n; j++){
        if(binary_search(adjs[j].begin(), adjs[j].end(), look)){
          AdjList[100*k + look].push_back(ii(100*j + look, 60));
          AdjList[100*j + look].push_back(ii(100*k + look, 60));
        }
      }
    }
  }
}

int main(){
  while(scanf("%d %d", &n, &sink) != EOF){
    AdjList.assign(10005, vii());
    adjs.assign(6, vi());
    for(int i = 0; i < n; i++){
      scanf("%d", &speed[i]);
    }
    cin.ignore();
    for(int i = 0; i < n; i++){
      string line, number; getline(cin, line);
      istringstream ss(line);
      while(ss >> number){
        adjs[i].push_back(atoi(number.c_str()));
      }
    }
    make_graph();
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    vi dist(10005, INF);
    for(int i = 0; i < n; i++){
      if(adjs[i][0] == 0){
        pq.push(ii(0, 100*i));
        dist[100*i] = 0;
      }
    }
    while(!pq.empty()){
      ii front = pq.top(); pq.pop();
      int d = front.first, u = front.second;
      if(d > dist[u]) continue;
      for(int j = 0; j < AdjList[u].size(); j++){
        ii v = AdjList[u][j];
        if(dist[u] + v.second < dist[v.first]){
          dist[v.first] = dist[u] + v.second;
          pq.push(ii(dist[v.first], v.first));
        }
      }
    }
    int ans = INF;
    for(int i = 0; i < n; i++){
      ans = min(ans, dist[100*i + sink]);
    }
    printf(ans == INF ? "IMPOSSIBLE\n" : "%d\n", ans);
  }
  return 0;
}
