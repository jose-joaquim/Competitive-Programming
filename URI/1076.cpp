#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

typedef vector<int> vi;

int n, m, ini;
vector<vi> adj;
vi dfs_num;

int dfs(int u) {
  dfs_num[u] = true;
  int cnt = 0;
  for (int v : adj[u]) {
    if (!dfs_num[v]) {
      cnt += 1 + dfs(v);
    }
  }
  return cnt;
}
int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d", &ini, &n, &m);
    adj.assign(n, vi());
    for (int i = 0; i < m; i++) {
      int u, v; scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs_num.assign(n, false);
    printf("%d\n", dfs(ini) * 2);
  }
  return 0;
}
