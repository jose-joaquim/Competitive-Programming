const int N = 1e5 + 10, LOGN = 20;
 
int n;
 
vector<int> adj[N];
int level[N], parent[N][LOGN];
 
void dfs(int u, int p, int l = 0){
  parent[u][0] = p;
  for(int k = 1; k < LOGN; k++){
    parent[u][k] = parent[parent[u][k - 1]][k - 1];
  }
  for(int i = 0; i < adj[u].size(); i++){
    int v = adj[u][i];
    if(v != p) dfs(v, u, l + 1);
  }
  level[u] = l;
}
 
int lca(int a, int b){
  if(level[a] < level[b]){
    swap(a, b);
  }
  for(int k = LOGN - 1; k >= 0; k--){
    if(level[a] - (1 << k) >= level[b]){
      a = parent[a][k];
    }
  }
  if(a != b){
    for(int k = LOGN - 1; k >= 0; k--){
      if(parent[a][k] != parent[b][k]){
        a = parent[a][k], b = parent[b][k];
      }
    }
    a = parent[a][0];
  }
  return a;
}

dfs(1, 1);
