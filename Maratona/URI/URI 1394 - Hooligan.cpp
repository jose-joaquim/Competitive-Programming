#include <assert.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <cstring>
#include <queue>
#include <bitset>

using namespace std;

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAX_V = 800;

int n, m, g, maxPoints, s, t;
int mf, f;
int points[MAX_V], G[MAX_V][MAX_V], res[MAX_V][MAX_V];
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge) {    
  if (v == s) { f = minEdge; return; }
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); 
    res[p[v]][v] -= f; res[v][p[v]] += f; }    
}

int main(){
  int cs = 0;
  while(scanf("%d %d %d", &n, &m, &g) && n != 0){
    AdjList.assign(MAX_V, vi());
    memset(points, 0, sizeof points);
    memset(res, 0, sizeof res);
    map<int, int> time;

    s = 0; t = 799;
    
    int totGames = ((n-1)*(n-2))/2;

    for(int i = 1; i < n; i++) time[i] = totGames + i;
    
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(i == j) continue;
        G[i][j] = m;
      }
    }

    //Ajeitando as capacidades
    fflush(stdin);
    for(int i = 0; i < g; i++){
      int a, c; char b;
      scanf("%d %c %d", &a, &b, &c);

      G[a][c]--, G[c][a]--;
      if(b == '<'){
        points[c] += 2;        
      }else if(b == '>'){
        points[a] += 2;
      }else{
        points[a]++, points[c]++;
      }
    }

    int gms = 1, toGo = 0;
    
    for(int i = 1; i < n; i++){
      for(int j = i + 1; j < n; j++){
        if(i == j) continue;
        if(G[i][j] > 0){
          
          int index = s + gms;
          gms++;
          
          toGo += res[s][index] = 2*G[i][j];
          

          res[index][time[i]] = INF;
          res[index][time[j]] = INF;

          AdjList[s].push_back(index);
          
          AdjList[index].push_back(time[i]);
          AdjList[time[j]].push_back(index);
          
          AdjList[index].push_back(time[j]);
          AdjList[time[j]].push_back(index);
        }
      }
    } 
    
    int R = 0, objective;
    bool go = true;
    
    for(int j = 1; j < n; j++) R += G[0][j];
    objective = points[0] + 2*R;
    
    for(int i = 1; i < n; i++){
      
      if((objective - points[i]) - 1 < 0){ go = false; break; }
      res[time[i]][t] = (objective - points[i]) - 1;
      AdjList[time[i]].push_back(t);
    }
    //
    
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

    if(!go){
      printf("N\n");
    }else{
      printf("%s\n", (mf+1 >= toGo) ? "Y" : "N");
    }
  }
  return 0;
}
