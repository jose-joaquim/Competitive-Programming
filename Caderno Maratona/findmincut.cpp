//We construct the residual graph Gf , and perform breadth-first search
//or depth-first search to determine the set A* of all nodes that
//s can reach. We then define B* = V - A*, and return the cut (A*, B*).

bool dfscut[MAXN];
vector<pair<int, int> > cutEdge;

void findMinCutEdges(int u){
  dfscut[u] = true;
  for(int i = 0; i < (int) adj[u].size(); i++){
    ii v = adj[u][i];
    if(res[u][v.first] && !dfscut[v.first]){
      dfs(v.first);
    }
  }
}

void getMinCut(){
  memset(dfscut, false, sizeof dfscut);

  dfs(source);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < (int) adj[i].size(); j++){
      if(visited[i] && !visited[j]){
        cutEdge.push_back(ii(i, j));
      }
    }
  }
}
