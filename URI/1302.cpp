#include <unordered_set>
#include <set>
#include <limits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <set>

#define len(x) ((int)x.size())

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXLOGN = 18;

struct Node {
  int p, h;
};

Node V[MAXN];
int N, memo[MAXN][MAXLOGN];

typedef struct ver {
  vector<int> v, dist_ref;
  ver(vector<int> cm) : v(cm) {
    dist_ref.assign(len(cm), numeric_limits<int>::max());
  }
}vertex;

vector<vertex> contracted;
vector<vector<int> > adj_contracted;
vector<vector<int> > adj;
vector<int> dfs_num, dfs_low, S, visited, comp;//, in_cycle;
pair<int, int> in_cycle[MAXN];
int n, dfscount, compcount, cycle;
int seen[MAXN];
pair<int, int> alcanca_ciclo[MAXN];
unordered_set<int> iscycle;

void init() {
  iscycle.clear();
  contracted.clear();
  adj_contracted.clear();
  adj.assign(n + 1, vector<int>());
  dfs_num.assign(n + 1, -1);
  dfs_low.assign(n + 1, 0);
  visited.assign(n + 1, 0);
  comp.assign(n + 1, -1);
  dfscount = 0;
  compcount = 0;
  cycle = 0;
  fill(in_cycle, in_cycle + MAXN, make_pair(-1, -1));
  fill(alcanca_ciclo, alcanca_ciclo + MAXN, make_pair(-1, -1));
}

void dfs_lca(int u, int depth, int parent) {
  V[u].h = depth;
  V[u].p = parent;

  for (int i = 0; i < adj_contracted[u].size(); ++i) {
    int v = adj_contracted[u][i];
    if (parent != v) {
      seen[v] = seen[u];
      dfs_lca(v, depth + 1, u);
    }
  }
}

void preprocessing() {
  for (int i = 0; i < MAXN; ++i)
    for (int j = 0; j < MAXLOGN; ++j)
      memo[i][j] = -1;
    
  for (int i = 1; i <= n; ++i)
    memo[i][0] = V[i].p;

  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 0; i <= n; ++i)
      if (memo[i][j - 1] != -1)
        memo[i][j] = memo[ memo[i][j-1] ][j-1];
}

int lca(int u, int v) {
  int tmp, log, i;

  if (V[u].h < V[v].h)
    swap(u, v);
  for (log = 1; (1 << log) <= V[u].h; ++log);
  --log;
    
  for (i = log; i >= 0; --i)
    if (V[u].h - (1 << i) >= V[v].h) {
      u = memo[u][i];
    }

  if (u == v) return u;

  for (i = log; i >= 0; --i) {
    if (memo[u][i] != -1 && memo[u][i] != memo[v][i])
      u = memo[u][i], v = memo[v][i];
  }

  return V[u].p;
}

void tarjanSCC(int u) {
  dfs_num[u] = dfs_low[u] = dfscount++;
  S.push_back(u);
  visited[u] = true;
  for (int v : adj[u]) {
    if (dfs_num[v] == -1) {
      tarjanSCC(v);
    }
    if (visited[v]) {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }

  if (dfs_low[u] == dfs_num[u]) {
    vector<int> v;
    compcount++;

    while (true) {
      int x = S.back(); S.pop_back(); visited[x] = false;
      v.push_back(x);
      comp[x] = compcount;
      
      if (u == x) break;
    }

    if (len(v) > 1) {
      cycle++;
      for (int i = len(v) - 1; i >= 0; i--) {
        in_cycle[v[i]] = make_pair(cycle, i + 1);
        iscycle.insert(compcount);
      }
    }

    contracted.push_back(vertex(v));
  }
}

pair<int, int> dfs(int u) {
  if (in_cycle[u].first != -1) { // Se u faz parte de um ciclo
    return in_cycle[u];
  } else {
    dfs_num[u] = true;
  }
  
  for (int v : adj[u]) {
    if (dfs_num[v] == -1) { // Se eu ainda nao visitei v
      alcanca_ciclo[u] = dfs(v);
    } else if (alcanca_ciclo[v].first != -1) { // Se v ja alcancou algum ciclo
      alcanca_ciclo[u] = alcanca_ciclo[v];
    }
  }

  return alcanca_ciclo[u];
}

void gatherSCC() {
  for (int i = 0; i < len(contracted); i++) {
    const vertex &c = contracted[i];
    for (int u : c.v) {
      for (int v : adj[u]) {
        if (comp[u] != comp[v]) {
          adj_contracted[comp[u]].push_back(comp[v]);
          adj_contracted[comp[v]].push_back(comp[u]);
        }
      }
    }
  }
}

int main() {
  while (scanf("%d", &n) != EOF) {
    init();
    for (int i = 1; i <= n; i++) {
      int fi; scanf("%d", &fi);
      adj[i].push_back(fi);
    }
    
    for (int i = 1; i <= n; i++) {
      if (dfs_num[i] == -1)
        tarjanSCC(i);
    }

    dfs_num.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
      if (in_cycle[i].first == -1 && dfs_num[i] == -1) {
        dfs(i);
      }
      if (in_cycle[i].first != -1) {
        alcanca_ciclo[i] = in_cycle[i];
      }
    }
    
    adj_contracted.assign(compcount + 1, vector<int>());
    gatherSCC();

    int saw = 1;
    memset(seen, -1, sizeof seen);
    for (int i = 1; i <= compcount; i++) {
      if (seen[i] == -1) {
        seen[i] = saw++;
        dfs_lca(i, 1, -1);
      }
    }
    preprocessing();
    
    int q; scanf("%d", &q);
    while(q--) {
      int u, v; scanf("%d %d", &u, &v);
      int w = lca(comp[u], comp[v]);
      int ans = 0;
      if (w != -1) {
        int aux = (V[comp[u]].h - V[w].h) + (V[comp[v]].h - V[w].h);
        ans += aux;
        if (iscycle.find(w) != iscycle.end()) {
          int x = alcanca_ciclo[u].second, y = alcanca_ciclo[v].second;
          ans += min(abs(x - y), len(contracted[w - 1].v) - abs(x - y));
        }
        printf("%d\n", ans);
      } else {
        puts("-1");
      }
    }
  }
  return 0;
}
