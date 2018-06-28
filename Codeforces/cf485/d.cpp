#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 1;
const int MAXG = 101;
const int INF = 1e9;

int n, m, k, s;
vector<vi> adj;
vector<vi> good_in;
int distg[MAXN][MAXG];

int main() {
  #ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #endif
  
  cin >> n >> m >> k >> s;

  good_in.assign(n + 1, vi());
  adj.assign(n + 1, vi());
  
  for(int i = 1; i <= n; i++) {
    int el; cin >> el;
    good_in[el].push_back(i);
  }

  adj.assign(n, vi());
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      distg[i][j] = INF;
    }
  }
  
  for (int gd = 1; gd <= k; gd++) {
    //printf("para o good %d\n", gd);
    queue<int> q;
    vector<int> dist(n + 1, INF);
    for (int x : good_in[gd]) {
      distg[x][gd] = 0;
      q.push(x);
      dist[x] = 0;
    }

    while(!q.empty()) {
      int v = q.front(); q.pop();
      for (int u : adj[v]) {
        if (dist[u] == INF) {
          distg[u][gd] = distg[v][gd] + 1;
          dist[u] = dist[v] + 1;
          q.push(u);
        }
      }
    }
    /*printf("    dists are:\n");
    for (int j = 1; j <= n; j++) {
      printf("%d ", distg[j][gd]);
    } puts("");*/
  }
  
  for (int i = 1; i <= n; i++) {
    sort(distg[i] + 1, distg[i] + k + 1);
  }

  /*puts("after sort");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      printf("%d ", distg[i][j]);
    } puts("");
  }*/

  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= s; j++) {
      ans += distg[i][j];
    }
    cout << ans << " ";
  } cout << '\n';
  return 0;
}
