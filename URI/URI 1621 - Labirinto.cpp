//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1621
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

const int MAXN = 501;
const int INF = 1000000000;

int n, m;
int adj[MAXN][MAXN], visited[MAXN][MAXN];

bool inside(int u, int v){
  return u >= 1 && u <= n && v >= 1 && v <= m;
}

int bfs(int u, int v, bool z){
  queue<ii> q;
  q.push(ii(u, v));

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      visited[i][j] = INF;

  visited[u][v] = 0;
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
    
  while(!q.empty()){
    ii top = q.front(); q.pop();
    int x = top.first, y = top.second;
    for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(inside(nx, ny) && adj[nx][ny] && visited[nx][ny] == INF){
        q.push(ii(x + dx[i], y + dy[i]));
        visited[x + dx[i]][y + dy[i]] = visited[x][y] + 1;
      }
    }
  }

  int mx = -1, u_n, v_n; 
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(adj[i][j] && visited[i][j] > mx){
        mx = visited[i][j];
        u_n = i;
        v_n = j;
      }
    }
  }

  
  if(!z) return bfs(u_n, v_n, 1);
  else return visited[u_n][v_n];
}

int main(){
  ios::sync_with_stdio(false);
  while((cin >> n >> m) && n){
    cin.ignore();
    for(int i = 1; i <= n; i++){
      string line; getline(cin, line);
      for(int j = 0; j < m; j++){
        if(line[j] == '#'){
          adj[i][j+1] = 0;
        }else{
          adj[i][j+1] = 1;
        }
      }
    }

    bool go = true;
    
    for(int i = 1; i <= n && go; i++){
      for(int j = 1; j <= m && go; j++){
        if(adj[i][j]){
          cout << bfs(i, j, 0) << '\n';
          go = false;
        }
      }
    }
  }
  return 0;
}
