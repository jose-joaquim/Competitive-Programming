#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int MAXN = (3 * 1e5) + 1;
int n, a, b;
vector<vi> adj;
int visited[MAXN];

void dfs(int u, int p) {
  //printf("to em %d\n", u);
  visited[u] = true;
  for(auto v : adj[u]) {
    if (v != p) {
      if (v != b) {
        dfs(v, u);
      }
    }
  }  
}

int main() {
  cin >> n >> a >> b;
  adj.assign(n + 1, vi());
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  int s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++) {
    if(visited[i]) {
      s1 += 1;
      printf("(1)%d\n", i);
    }else {
      s2 += 1;
      printf("(2)%d\n", i);
    }
  }
  printf("s1 %d s2 %d\n", s1, s2);
  int ans = (s1 * (s1 - 1)) + (s2 * (s2 - 1)) + (s1 * s2);
  if (s1 == 1) ans++;
  if (s2 == 1) ans++;
  cout << ans << endl;
  return 0;
}
