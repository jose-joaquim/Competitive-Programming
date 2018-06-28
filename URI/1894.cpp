#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

typedef vector<int> vi;

const int MAXN = 1e4 + 10;
const int MAXL = 1e3 + 10;

int maxDepth;
int n, l;
int raiz;
int dfs_num[MAXN];
char code[MAXN][MAXL];

vector<vi> adj;

int hamming(char* f1, char* f2) {
  int ret = 0;
  for (int i = 0; i < l; i++) {
    if (f1[i] != f2[i]) {
      ret += 1;
    }
  }
  return ret;
}

void computelevel(int u, int length) {
  maxDepth = max(length, maxDepth);
  dfs_num[u] = 1;
  for (int v : adj[u]) {
    if (dfs_num[v] == -1) {
      computelevel(v, length + 1);
    }
  }
}

void dfs(int u, int pai) {
  dfs_num[u] = true;
  for (int v : adj[u]) {
    if (dfs_num[v] == -1) {
      dfs(v, u);
    }
  }
  
  if (u > n) { // se eu nao sou uma folha
    char* f1 = code[adj[u][0]];
    char* f2 = code[adj[u][1]];
    int dist = hamming(f1, f2);
    
  }  
}

int main() {
  scanf("%d %d", &n, &l);
  raiz = (n * 2) - 1;
  for (int i = 0; i < n; i++) {
    scanf("%s", code[i]);
  }
  
  memset(dfs_num, -1, sizeof dfs_num);
  adj.assign(2*n, vi());
  
  for (int i = 0; i < 2 * (n - 1); i++) {
    int u, v; scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  computelevel(raiz, 0);
  cout << maxDepth << endl;
  return 0;
}
