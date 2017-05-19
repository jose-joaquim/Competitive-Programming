//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1806
#include <queue>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


const int INF = 1000000000;
const int MXV = 10001;

int n, c, s, b;
int k, f, bino;
vi criminals;
vector<vii> AdjList;//, distCriminals;
set<ii> prohibited;
map<ii, int> length;
vi distBino, hasShortest, pai;

bool canGo(int u, int v){ return prohibited.find(ii(u, v)) == prohibited.end(); }

void readInput(){
  AdjList.assign(n + 1, vii());
  criminals.assign(n + 1, 0);
  hasShortest.assign(n + 1, 0);
  pai.assign(n + 1, 0);
  for(int i = 0; i < c; i++){
    int u, v, w; //scanf("%d %d %d", &u, &v, &w);
    cin >> u >> v >> w;
    AdjList[u].push_back(ii(v, w));
    AdjList[v].push_back(ii(u, w));
  }
  for(int i = 0; i < s; i++){
    int u, v, w; //scanf("%d %d %d", &u, &v, &w);
    cin >> u >> v >> w;
    AdjList[u].push_back(ii(v, w));
    AdjList[v].push_back(ii(u, w));
    prohibited.insert(ii(u, v));
    prohibited.insert(ii(v, u));

  }
  for(int i = 0; i < b; i++){
    int u; //scanf("%d", &u);
    cin >> u;
    criminals[u]++;
  }
  cin >> k >> f;
}

int dijkstra(bool criminal){
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  if(criminal){
    vi dist(n + 1, INF); dist[f] = 0;
    pq.push(ii(0, f));
    while(!pq.empty()){
      ii front = pq.top(); pq.pop();
      int d = front.first, u = front.second;
      if(dist[u] > d) continue;
      for(int j = 0; j < (int) AdjList[u].size(); j++){
        ii v = AdjList[u][j];
        int w = v.second + dist[u];
        if(dist[v.first] > w){
          dist[v.first] = w;
          pq.push(ii(w, v.first));
        }
      }
    }    
    int ans = 0;
    for(int i = 1; i <= n; i++){
      if(criminals[i] > 0){
        if(dist[i] <= bino) ans += criminals[i];
      }
    }
    return ans;
  }else{
    distBino.assign(n + 1, INF);
    distBino[f] = 0;
    pq.push(ii(distBino[f], f));
    while(!pq.empty()){
      ii front = pq.top(); pq.pop();
      int d = front.first, u = front.second;
      if(distBino[u] > d) continue;
      for(int j = 0; j < (int) AdjList[u].size(); j++){
        ii v = AdjList[u][j];
        if(distBino[v.first] > distBino[u] + v.second && canGo(u, v.first)){
          distBino[v.first] = distBino[u] + v.second;
          pq.push(ii(distBino[v.first], v.first));
        }
      }
    }

    //printf("bino eh %d\n", distBino[k]);
    bino = distBino[k];
  }
  return -1;
}



int main(){
  std::ios::sync_with_stdio(false);
  cin >> n >> c >> s >> b;
  readInput();
  //cout << dijkstra(false) << '\n';
  //cout << length << '\n';
  dijkstra(false);
  cout << dijkstra(true) << '\n';
  return 0;
}
