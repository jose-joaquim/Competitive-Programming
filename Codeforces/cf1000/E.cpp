#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 10;

typedef vector<int> vi;

int n, m, dfscount, dfsroot, rootChildren, ans;
vector<vi> adj;
vi dfs_num, dfs_low, dfs_parent;

void dfs(int u) {
  dfs_low[u] = dfs_num[u] = dfscount++;

  for (int v : adj[u]) {
    if (dfs_num[v] == -1) {
      dfs_parent[v] = u;
      dfs(v);

      if (dfs_low[v] > dfs_num[u]) {
        //printf("(%d, %d) is a bridge\n", u, v);
        ans++;
      }

      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else if (v != dfs_parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

int main() {
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif

  cin >> n >> m;

  adj.assign(n + 1, vi());
  dfs_num.assign(n + 1, -1);
  dfs_low.assign(n + 1, 0);
  dfs_parent.assign(n + 1, 0);
  
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (dfs_num[i] == -1) {
      dfs(i);
    }
  }

  cout << ans << '\n';
  return 0;
}
