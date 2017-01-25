//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1085
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef pair<string, string> ss;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, s, t;
string source, sink;
vector<string> vetW;
vector<vii> AdjList;
unordered_map<int, ii> intPair;

bool share(int i, int j){
  ii &o1 = intPair[i], &o2 = intPair[j];
  if(o1.first == o2.first || o1.first == o2.second || o1.second == o2.first || o1.second == o2.second){
    return true;
  }
  return false;
}

void make_graph(){
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(vetW[i][0] != vetW[j][0] && share(i, j)){
        AdjList[i].push_back(ii(j, (int) vetW[i].size()));
        AdjList[j].push_back(ii(i, (int) vetW[j].size()));
      }
    }
  }
  
  for(int i = 0; i < n; i++){
    ii o1 = intPair[i];
    if(s == o1.first || s == o1.second){
      AdjList[s].push_back(ii(i, 0));
      AdjList[i].push_back(ii(s, 0));
    }
    if(t == o1.first || t == o1.second){
      AdjList[t].push_back(ii(i, (int) vetW[i].size()));
      AdjList[i].push_back(ii(t, (int) vetW[i].size()));
    }
  }
}

int main(){
  while(scanf("%d", &n) && n){
    vetW.clear();
    intPair.clear();
    AdjList.assign(n + 3, vii());
    cin >> source >> sink;
    s = n + 1; t = n + 2;
    int idS = 0;
    unordered_map<string, int> map_ID;
    map_ID[source] = s; map_ID[sink] = t;
    for(int i = 0; i < n; i++){
      string w1, w2, c;
      cin >> w1 >> w2 >> c;
      if(map_ID.find(w1) == map_ID.end()){
        map_ID[w1] = idS++;
      }
      if(map_ID.find(w2) == map_ID.end()){
        map_ID[w2] = idS++;
      }
      vetW.push_back(c);
      intPair[i] = make_pair(map_ID[w1], map_ID[w2]);
    }
    make_graph();
    vi dist(n + 3, INF); dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));
    while(!pq.empty()){
      ii front = pq.top(); pq.pop();
      int d = front.first; int u = front.second;
      if(d > dist[u]) continue;
      for(int i = 0; i < (int) AdjList[u].size(); i++){
        ii v = AdjList[u][i];
        if(dist[u] + v.second < dist[v.first]){
          dist[v.first] = dist[u] + v.second;
          pq.push(ii(dist[v.first], v.first));
        }
      }
    }
    printf(dist[t] == INF ? "impossivel\n" : "%d\n", dist[t]);
  }
  return 0;
}
