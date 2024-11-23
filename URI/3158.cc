#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
vi taken;
priority_queue<ii> pq;

void process(int u) {
  taken[u] = 1;
  for (auto &[v, w] : adj[u])
    if (!taken[v])
      pq.push({-w, -v});
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int n, m, b, e;
    cin >> n >> m >> b >> e;
    adj.assign(n, vii());
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].emplace_back(v, e);
      adj[v].emplace_back(u, e);
    }

    if (b <= e) {
      cout << (1LL * b) * (1LL * n) << endl;
      continue;
    }

    taken.assign(n, 0);
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
      if (taken[i])
        continue;

      int mst_cost = 0, visited = 1;
      process(i);

      while (!pq.empty()) {
        auto [w, u] = pq.top();
        visited++;
        pq.pop();
        w = -w;
        u = -u;
        if (taken[u])
          continue;

        mst_cost += w;
        process(u);
      }

      if (visited == 1)
        ans += b;
      else
        ans += mst_cost + b;
    }

    cout << ans << endl;
  }

  return 0;
}
