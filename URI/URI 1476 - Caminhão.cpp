//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1476
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
 
#define INF 1000000000
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int n, m, s, maiorAltura, segmento, ans;
vector<vii> AdjList;
map<ii, int> mapAdj;
vi pai, superPai, nivel, menor;

class UnionFind {                    
private:
  vi p, rank, setSize;               
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
      int x = findSet(i), y = findSet(j);

      if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
      else                   { p[x] = y; setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void montaArvore(int u, int p, int l){

  pai[u] = p;
  nivel[u] = l;

  if(l > maiorAltura) {
    maiorAltura = l;
  }

  for(int i = 0; i < (int) AdjList[u].size(); i++){
    ii v = AdjList[u][i];

    if(!pai[v.first]){
      montaArvore(v.first, u, l + 1);
    }
  }
}

void montaSuperPai(int u, int p){
  superPai[u] = p;

  if(nivel[u]%segmento == 0){
    p = u;
  }

  for(int i = 0; i < (int) AdjList[u].size(); i++){
    ii v = AdjList[u][i];
    if(!superPai[v.first]){
      montaSuperPai(v.first, p);
    }
  }
}

int lca(int a, int b){
  while(superPai[a] != superPai[b]){
    if(nivel[a] > nivel[b]){
      ans = min(ans, menor[a]);
      a = superPai[a];
    }else{
      ans = min(ans, menor[b]);
      b = superPai[b];
    }
  }
  while(a != b){
    if(nivel[a] > nivel[b]){
      ans = min(ans, mapAdj[ii(a, pai[a])]);
      a = pai[a];
    }else{
      ans = min(ans, mapAdj[ii(b, pai[b])]);
      b = pai[b];
    }
  }
  return a;
}

void preMenor(int u){
  int sP = superPai[u];
  int p_ = pai[u];
  menor[u] = mapAdj[ii(u, p_)];
  while(p_ != sP){
    int nvPai = pai[p_];
    int now = p_;
    p_ = nvPai;
    menor[u] = min(menor[u], mapAdj[ii(now, p_)]);
  }
}
 
int main(){
  while(scanf("%d %d %d", &n, &m, &s) != EOF){
    mapAdj.clear();
    AdjList.assign(n + 1, vii());
    pai.assign(n + 1, 0);
    superPai.assign(n + 1, 0);
    nivel.assign(n + 1, 0);
    menor.assign(n + 1, INF);
    
    vector<iii> EdgeList;
    for(int i = 0; i < m; i++){
      int u, v, w; scanf("%d %d %d", &u, &v, &w);
      EdgeList.push_back(iii(w, ii(u, v)));
    }
    sort(EdgeList.begin(), EdgeList.end(), greater<iii>());
    UnionFind UF(n + 1);
    for(int i = 0; i < (int) EdgeList.size(); i++){
      iii front = EdgeList[i];
      int u = front.second.first, v = front.second.second, w = front.first;
      if(!UF.isSameSet(u, v)){
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
        
        mapAdj[ii(u, v)] = w;
        mapAdj[ii(v, u)] = w;

        UF.unionSet(u, v);
      }
    }

    maiorAltura = 0;
    montaArvore(1, 1, 0);
    segmento = sqrt(maiorAltura);
    montaSuperPai(1, 1);
    for(int i = 2; i <= n; i++) preMenor(i);
    
    while(s--){
      int u, v; scanf("%d %d", &u, &v);
      ans = INF;
      lca(u, v);
      printf("%d\n", ans);
    }
  }
  return 0;
}
