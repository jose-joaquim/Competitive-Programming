//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1499
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vii;

int n, q;

typedef struct treeStruct{
  int sz, diameter;
  vector<vi> adj;
  vi level, degree, centers, E;
  vi cnt;
  treeStruct(int n) : sz(n){
    adj.assign(sz + 1, vi());
    level.assign(sz + 1, 0);
    degree.assign(sz + 1, 0);
    E.assign(sz + 1, 0);
  }
}tree;

void read(tree &t, int w){
  for(int i = 0; i < w - 1; i++){
    int u, v; scanf("%d %d", &u, &v);
    t.adj[u].push_back(v);
    t.adj[v].push_back(u);
    t.degree[u]++, t.degree[v]++;
  }
}

int getCenters(tree &t){
  
  queue<int> q;
  int maxlevel = 0;
  for(int i = 1; i <=  t.sz; i++){
    if(t.degree[i] == 1){
      q.push(i);
    }
  }
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int i = 0; i < (int) t.adj[u].size(); i++){
      int v = t.adj[u][i];
      if(--t.degree[v] == 1){
        q.push(v);
        t.level[v] = t.level[u] + 1;
        maxlevel = max(maxlevel, t.level[v]);
      }
    }
  }

  for(int i = 1; i <= t.sz; i++){
    if(t.level[i] == maxlevel){
      t.centers.push_back(i);
    }
  }

  for(int i = 0; i < (int) t.centers.size(); i++){
    t.E[t.centers[i]] = (maxlevel*2 + t.centers.size() - 1 + 1)/2;
  }

  t.diameter = (maxlevel*2 + t.centers.size() - 1);

  return maxlevel*2 + t.centers.size() - 1;
}


bool notACenter(int i, tree &t){
  if(t.centers.size() == 2)
    return i != t.centers[0] && i != t.centers[1];
  
  return i != t.centers[0];
}

void dfs(tree &t, int u, int length){
  t.E[u] = length + t.E[t.centers[0]];
  for(int i = 0; i < (int) t.adj[u].size(); i++){
    int v = t.adj[u][i];
    if(!t.E[v] && notACenter(v, t)){
      dfs(t, v, length + 1);
    }
  }
}


void getEccentricity(tree &t){
  //E(v) = d(v, u) + E(c)

  for(int i = 0; i < (int) t.centers.size(); i++){
    dfs(t, t.centers[i], 0);
  }

  t.cnt.assign(t.diameter + 1, 0);
  for(int i = 1; i <= t.sz; i++){
    t.cnt[t.E[i]]++;
  }
}

long double getSum(tree &t1, tree &t2){
  long double ans = 0, dv = 0;

  for(int i = 0; i < (int) t1.cnt.size(); i++){
    for(int j = 0; j < (int) t2.cnt.size(); j++){
      int mx = max(max(t1.diameter, t2.diameter), 1 + i + j);
      ans += (mx * t1.cnt[i] * t2.cnt[j]) * 1.0 ;
      dv += (t1.cnt[i] * t2.cnt[j]) * 1.0;
    }
  }

  return ans/dv;
}

int main(){
  while(scanf("%d %d", &n, &q) != EOF){
    tree treeN(n), treeQ(q);
    read(treeN, n);
    read(treeQ, q);

    getCenters(treeN);
    getCenters(treeQ);
    getEccentricity(treeN);
    getEccentricity(treeQ);
    printf("%.3Lf\n", getSum(treeN, treeQ));
  }
  return 0;
}
