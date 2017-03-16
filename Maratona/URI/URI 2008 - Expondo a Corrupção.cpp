//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2008

#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <cstring>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int r, b;
vi preco, partido
vector<vi> AdjList;
int A[205][10005];
int par[2];

int dfs_num[1000];
int dsp, ppp, sum;
vector<int> V, W;

void dfs(int s, int u){
  dfs_num[u] = 1;
  sum += preco[u];
  if(!s) dsp++; else ppp++;
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(dfs_num[v] == -1){
      dfs(1 - s, v);
    }
  }
}

int value(int id, int w) {
  if (w < 0) return -INF;
  if (id == (int) V.size()) return 0;
  if (A[id][w] != -1)    return A[id][w];
  if (W[id] > w)         return A[id][w] = value(id + 1, w);
  return A[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
}

int PPP(){
  memset(A, -1, sizeof A);
  memset(dfs_num, -1, sizeof dfs_num);
  V.clear(); W.clear();
  for(int i = 1; i <= par[0] + par[1]; i++){
    dsp = ppp = sum = 0;
    if(dfs_num[i] == -1){
      dfs(partido[i], i);
    }
    if(dsp > ppp){
      V.push_back(dsp - ppp);
      W.push_back(sum);
    }
  }
  return par[1] + value(0, b);
}

int DSP(){
  memset(A, -1, sizeof A);
  memset(dfs_num, -1, sizeof dfs_num);
  V.clear(); W.clear();
  for(int i = 1; i <= par[0] + par[1]; i++){
    dsp = ppp = sum = 0;
    if(dfs_num[i] == -1){
      dfs(partido[i], i);
    }
    if(ppp > dsp){
      V.push_back(ppp - dsp);
      W.push_back(sum);
    }
  }
  return par[0] + value(0, b);
}

int main(){
  scanf("%d %d %d %d", &par[0], &par[1], &r, &b);  
  AdjList.assign(par[0] + par[1] + 2, vi());
  preco.assign(par[0] + par[1] + 2, 0);
  partido.assign(par[0] + par[1] + 2, 0);
  for(int i = 1; i <= par[0]; i++){
    scanf("%d", &preco[i]);
    partido[i] = 0;
  }
  for(int i = 1; i <= par[1]; i++){
    scanf("%d", &preco[par[0] + i]);
    partido[par[0] + i] = 1;
  }
  for(int i = 0; i < r; i++){
    int u, v; scanf("%d %d", &u, &v);
    AdjList[u].push_back(par[0] + v);
    AdjList[par[0] + v].push_back(u);
  }
  printf("%d %d\n", DSP(), PPP());
  return 0;
}
