#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>

#define INF 1000000000
#define UNVISITED -1
#define VISITED 1
#define RAIZ 0

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, F;
int mark[100005], degree[100005];
int dp[100005][2];
vector<int> dfs_num;
vector<vii> AdjList;

int dfs(int u){
  dfs_num[u] = VISITED;
  if(mark[u]) degree[u]++;
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    ii v = AdjList[u][i];
    if(dfs_num[v.first] == UNVISITED){
      degree[u] += dfs(v.first);
    }
  }
  return degree[u];
}

int solve(int u, bool indo){
  if(dp[u][indo] != -1) return dp[u][indo];
  int ans = 0, ans2 = 0;;
  if(indo){
    for(int i = 0; i < (int) AdjList[u].size(); i++){
      ii v = AdjList[u][i];
      if(degree[v.first]) ans += v.second + solve(v.first, true);
    }
  }else{
    for(int i = 0; i < (int) AdjList[u].size(); i++){
      ii v = AdjList[u][i];
      if(degree[v.first]){
	ans += v.second + solve(v.first, !indo);
	ans2 = max(ans2, v.second + solve(v.first, !indo) - solve(v.first, indo));
      }
    }
  }
  return dp[u][indo] = ans - ans2;
}

int main(int argc, char **argv)
{
  while(scanf("%d %d", &N, &F) != EOF){
    AdjList.assign(N, vii());
    dfs_num.assign(N, UNVISITED);
    memset(mark, 0, sizeof mark);
    memset(dp, -1, sizeof dp);
    memset(degree, 0, sizeof degree);
    for(int i = 0; i < N - 1; i++){
      int u, v, w;
      scanf("%d %d %d\n", &u, &v, &w);
      AdjList[u-1].push_back(ii(v-1, w));
      //AdjList[v-1].push_back(ii(u-1, w));
    }
    // puts("aksdk");
    for(int i = 0; i < F; i++){
      int u;
      scanf("%d", &u);
      mark[u-1] = 1;
    }
    dfs(RAIZ);
    //puts("oi");

    printf("%d\n", solve(RAIZ, 0));
  }
  return 0;
}

