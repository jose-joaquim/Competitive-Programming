//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2404
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

class UnionFind{
private: vi p, rank;
public:
  UnionFind(int N){ 
    rank.assign(N, 0);
    p.assign(N, 0);
    for(int i = 0; i < N; i++){
      p[i] = i;
    }
  }
  int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
  void unionSet(int i, int j){
    if(!isSameSet(i, j)){
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) p[y] = x;
      else{				  p[x] = y;
        if(rank[x] == rank[y]) rank[y]++; }
    }
  }
};

int n, m;

int main(){
  scanf("%d %d", &n, &m);
  vector<iii> EdgeList;
  for(int i = 0; i < m; i++){
    int u, v, w; scanf("%d %d %d", &u, &v, &w);
    EdgeList.push_back(iii(w, ii(u, v)));
  }
  sort(EdgeList.begin(), EdgeList.end());
  UnionFind UF(n + 1);
  int ans = 0;
  for(int i = 0; i < m; i++){
    iii front = EdgeList[i];
    if(!UF.isSameSet(front.second.first, front.second.second)){
      ans += front.first;
      UF.unionSet(front.second.first, front.second.second);
    }
  }
  printf("%d\n", ans);
  return 0;
}
