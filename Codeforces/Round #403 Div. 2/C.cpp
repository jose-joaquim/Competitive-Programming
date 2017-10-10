#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define VISITED 1
#define UNVISITED -1

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> AdjList;
vi colors, dfs_num;
queue<int> onQueue;
int totalColors = 0;

//.first eh cor do vertice, .second eh cor do pai do vertice
void dfs(int u, ii cor){
  map<int, bool> proibida;
  proibida[cor.first] = true;
  proibida[cor.second] = true;
  //printf("to no vertice %d, cor dele eh %d, cor do pai eh %d\n", u, cor.first, cor.second);
  dfs_num[u] = VISITED;
  int lastCor = 1;
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(dfs_num[v] == UNVISITED){
      int corFilho, ok = 0;
      for(int j = lastCor; ; j++){
        if(j != cor.first && j != cor.second){
          colors[v] = corFilho = j;
          ok = true;
          lastCor = j + 1;
          break;
        }
      }
      dfs(v, ii(corFilho, cor.first));
    }
  }
}

int main(){
  int n; cin >> n;
  AdjList.assign(n + 1, vi());
  colors.assign(n + 1, 0);
  dfs_num.assign(n + 1, UNVISITED);
  for(int i = 0; i < n-1; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
  }
  colors[1] = 1;
  dfs(1, ii(1, 1));
  int ans = -1;
  for(int i = 1; i < (int) colors.size(); i++){
    ans = max(ans, colors[i]);
  }
  printf("%d\n", ans);
  for(int i = 1; i < (int) colors.size(); i++){
    printf("%d ", colors[i]);
  }
  puts("");
  return 0;
}
