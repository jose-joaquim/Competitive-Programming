#include <bits/stdc++.h>

using namespace std;

#define UNVISITED -1
#define VISITED 1
#define INF 1000000000

typedef vector<int> vi;

int vet[1005], found[1005];
int n, m;
vector<vi> AdjList;
vi dfs_num;

void dfs(int u){
  dfs_num[u] = VISITED;
  found[vet[u]] = 1;
  // printf("%d tem a chave de %d\n", u, vet[u]);
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    int v = AdjList[u][i];
    if(found[v]){
      if(dfs_num[v] == UNVISITED){
	dfs(v);
      }
    }//else printf("%d nao tem a chave de %d (tem %d em vet[%d])\n", u, v, vet[u], u);
  }
}

int main(){
  while(scanf("%d %d", &n, &m) != EOF){
    memset(found, 0, sizeof found);
    AdjList.assign(n+1, vi());
    dfs_num.assign(n+1, UNVISITED);
    dfs_num[1] = found[1] = VISITED;
    bool ans = true;
    //puts("spdk");
    for(int i = 0; i < m; i++){
      int u, v;
      scanf("%d %d", &u, &v);
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
    }
    vi dist(n+1, INF);
    queue<int> q, q_aux; q.push(1);
    dist[1] = 0;
    //puts("eoq");
    for(int i = 2; i <= n; i++){
      int u; scanf("%d", &u);
      vet[u] = i;
      //printf("%d tem a chave de %d\n", u, i);
    }
    while(!q.empty()){
      int u = q.front(); q.pop();
      found[vet[u]] = 1;
      for(int i = 0; i < (int) AdjList[u].size(); i++){
	int v = AdjList[u][i];
	if(found[v] && dist[v] == INF){
	  dist[v] = dist[u] + 1;
	  q.push(v);
	}else if(!found[v]){
	  printf("nao deu pra visitar %d agora (v %d)\n", v, u);
	  q_aux.push(v);
	}
      }
    }
    while(!q_aux.empty()){
      int u = q_aux.front();
      if(found[u]){
	printf("achei a de %d no meio do caminho\n", u);
	dist[u] = 1;
      }
      q_aux.pop();
    }
    for(int i = 1; i <= n; i++){
      if(dist[i] == INF){
	printf("%d ficou sem ser visitada\n", i);
	ans = false;
      }
    }
    /* dfs(1);
    bool ans = true;
    for(int i = 1; i <= n; i++){
      if(dfs_num[i] == UNVISITED){
	printf("%d ficou sem ser visitada\n", i);
	ans = false;
	//	break;
      }
    }*/
    puts(ans ? "sim" : "nao");
  }
  return 0;
}
