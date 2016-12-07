//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=694
#include <bits/stdc++.h>

//left side: devices || right side: receptacle

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vi match, vis;
int n, m, k;
map<string, vector<int> > plug;
map<string, string> device;
map<string, vector<string> > adapter;
map<string, bool> visited;
vector<string> nameDevices;

int Aug(int l) {
  if (vis[l]) return 0;      
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;
  } }
  return 0;           
}

void searchAdapter(string u, int who){
  visited[u] = true;
  if(plug.find(u) != plug.end()){
    for(int i = 0; i < (int) plug[u].size(); i++){
      AdjList[who].push_back(plug[u][i] + m);
    }
  }
  for(int i = 0; i < (int) adapter[u].size(); i++){
    if(visited.find(adapter[u][i]) == visited.end()){
      searchAdapter(adapter[u][i], who);
    }
  }
}

void make_graph(){
  for(int i = 0; i < m; i++){
    visited.clear();
    searchAdapter(device[nameDevices[i]], i);
  }
}

void init(){
  adapter.clear();
  plug.clear();
  device.clear();
  nameDevices.clear();
}
    
int main(){
  int cs; scanf("%d", &cs);
  bool go = false;
  while(cs--){
    if(go) printf("\n");
    else go = true;
    scanf("%d", &n);
    init();
    for(int i = 0; i < n; i++){
      string type; cin >> type;
      //assert(plug.find(type) == plug.end() && "Ops, plug repetido!");
      plug[type].push_back(i);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
      string dev, w;
      cin >> dev >> w;
      device[dev] = w;
      nameDevices.push_back(dev);
    }
    AdjList.assign(n + m + 2, vi());
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
      string n1, n2;
      cin >> n1 >> n2;
      adapter[n1].push_back(n2);
    }
    make_graph();
    int V = n + m, Vleft = m;
    int MCBM = 0;
    match.assign(V, -1);    
    for (int l = 0; l < Vleft; l++) {
      vis.assign(Vleft, 0);          
      MCBM += Aug(l);
    }
    printf("%d\n", m - MCBM);
  }
  return 0;
}
