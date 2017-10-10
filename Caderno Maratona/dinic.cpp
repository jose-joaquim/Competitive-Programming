bool bfs(int source, int sink){
  queue<int> q;
  for(int i = 0; i < MAXV; i++) dist[i] = INF;
  q.push(source);
  dist[source] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int j = 0; j < (int) adj[u].size(); j++){
      ii v = adj[u][j];
      if(res[v.first][u] < v.second && dist[v.first] == INF){
        dist[v.first] = dist[u] + 1;
        q.push(v.first);
      }
    }
  }
  return dist[sink] != INF;
}

int augment(int u, int minflow){
  if(u == t){
    return minflow;
  }
  for(int j = 0; j < (int) adj[u].size(); j++){
    ii v = adj[u][j];
    if((dist[v.first] == dist[u] + 1) && res[v.first][u] < v.second){
      int curr = min(minflow, v.second - res[v.first][u]);
      int temp = augment(v.first, curr);
      if(temp){
        res[v.first][u] += temp;
        res[u][v.first] -= temp;
        return temp;
      }
    }
  }
  return 0;
}

int dinic(int source, int sink){
  int flow = 0;
  while(bfs(source, sink)){
    while(int f = augment(source, INF)){
      flow += f;
    }
  }
  return flow;
}
