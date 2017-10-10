//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1025
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#include <assert.h>

using namespace std;

#define INF 1000000000

typedef vector<int> vi;

vector<vi> AdjList;

const int MAX_V = 110;

int res[MAX_V][MAX_V], mf, f, s, t;                      
vi p;

void augment(int v, int minEdge) {    
  if (v == s) { f = minEdge; return; }
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
                         res[p[v]][v] -= f; res[v][p[v]] += f; }   
}

int main(){
  int n; cin >> n;
  s = 0, t = 109;
  vi votes(MAX_V, 0);
  
  int adjVote[n+1][2];
  
  for(int i = 1; i <= n; i++){
    int u, v; cin >> u >> v;
    votes[u]++, votes[v]++;
    adjVote[i][0] = u;
    adjVote[i][1] = v;
  }
  
  int ans = n;
  
  for(int wf = 1; wf <= n; wf++){

    AdjList.assign(MAX_V, vi());

    int forb1 = adjVote[wf][0], forb2 = adjVote[wf][1];

    if(votes[wf] < 2) continue;
    
    for(int i = 1; i <= n; i++){
      if(i == wf) continue;
      AdjList[s].push_back(i);
      AdjList[i].push_back(s);
      AdjList[i + n].push_back(t);
      AdjList[t].push_back(i + n);
    }
    
    for(int i = 0; i < MAX_V; i++){
      for(int j = 0; j < MAX_V; j++){
        res[i][j] = 0;
      }
    }

    bool go = true;
    
    for(int i = 1; i <= n && go; i++){
      if(i == wf) continue;
      res[s][i] = 1;
      int v1 = adjVote[i][0], v2 = adjVote[i][1];

      if(v1 != wf && v2 != wf){
        AdjList[i].push_back(v1 + n);
        AdjList[v1 + n].push_back(i);

        AdjList[i].push_back(v2 + n);
        AdjList[v2 + n].push_back(i);

        int a = res[i][v1 + n] = res[v1 + n][t] = votes[wf] - 1;
        int b = res[i][v2 + n] = res[v2 + n][t] = votes[wf] - 1;
        if(a < 0) go = false;
        if(b < 0) go = false;
      }
    }

    res[n + forb1][t] = votes[wf] - 2;
    res[n + forb2][t] = votes[wf] - 2;

    mf = 0;
    while (1 & go) {                 
      f = 0;
      bitset<MAX_V> vis; vis[s] = true; 
      queue<int> q; q.push(s);
      p.assign(MAX_V, -1);
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        for (int j = 0; j < (int)AdjList[u].size(); j++) { 
          int v = AdjList[u][j];
          if (res[u][v] > 0 && !vis[v])
            vis[v] = true, q.push(v), p[v] = u;
        }
      }
      augment(t, INF);
      if (f == 0) break;
      mf += f;
    }

    /*printf("lobo eh %d\n", wf);
    cout << mf << endl;
    cout << n << " || " << votes[wf] << " || " << go << endl;*/

    if(go && mf == n - 1 - votes[wf]){
      ans--;
    }
  }
  
  printf("%d\n", ans);
  
  return 0;
}
