#include <bits/stdc++.h>

using namespace std;

#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2

const int MAX_N = 1e5 + 10 + 30;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList, AdjList2;
vi dfs_num;
//map<ii, bool> put;
map<int, vi> comp_cycle;
map<int, bool> belongsCycle;
int n, nCycle, altura;
int pai[MAX_N], nivel[MAX_N], super_pai[MAX_N], segmento;
vi dfs_low, S, visited, raizes_ciclos, dfs_parent;
int numSCC, dfsNumberCount;
int vez; stack<int> pilha;

void monta_arvore(int u, int p, int l) {
  pai[u] = p;
  nivel[u] = l;
    
  if(l > altura) {
    altura = l;
  }

  for(int i=0; i<(int)AdjList2[u].size(); i++) {
    int v = AdjList2[u][i];

    if(!pai[v]) {
      monta_arvore(v, u, l+1);
    }
  }
}

void monta_super_pai(int u, int p) {
  puts("Oi");
  super_pai[u] = p;

  if(nivel[u]%segmento == 0) {
    p = u;
  }

  for(int i=0; i<(int)AdjList2[u].size(); i++) {
    int v = AdjList2[u][i];

    if(!super_pai[v]) {
      monta_super_pai(v, p);
    }
  }
}

int LCA(int a, int b) {
  while(super_pai[a] != super_pai[b]) {
    if(nivel[a] > nivel[b]) {
      a = super_pai[a];
    } else {
      b = super_pai[b];
    }
  }
  while(a != b) {
    if(nivel[a] > nivel[b]) {
      a = pai[a];
    } else {
      b = pai[b];
    }
  }
  return a;
}

void dfs(int u){
  dfs_num[u] = VISITED;
  for(int i = 0; i < (int) AdjList[u].size(); i++){

  }
}

void tarjanSCC(int u){
  dfs_num[u] = dfs_low[u] = dfsNumberCount++;
  visited[u] = true;
  S.push_back(u);
  for(int i = 0; i < (int) AdjList[u].size(); i++){
    //printf("encontrei v igual a %d\n", AdjList[u][i]);
    int v = AdjList[u][i];
    if(dfs_num[v] == UNVISITED){
      tarjanSCC(v);
    }
    if(visited[v]){
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    
  }
  if(dfs_num[u] == dfs_low[u]){
    printf("SCC %d:", ++numSCC);
    comp_cycle[u].push_back(u);
    raizes_ciclos.push_back(u);
    while(true){
      int v = S.back(); S.pop_back(); visited[v] = false;
      printf(" %d", v);
      if(u == v) break;
      comp_cycle[u].push_back(v);
    }
    puts("");
  }
}

void graphCheck(int u){
  dfs_num[u] = EXPLORED;
  for(int j = 0; j < (int) AdjList[u].size(); j++){
    int v = AdjList[u][j];
    if(dfs_num[v] == UNVISITED){
      dfs_parent[v] = u;
      pilha.push(v);
      graphCheck(v);
    }else if(dfs_num[v] == EXPLORED){
      /*printf("achei vertice explorado em (%d, %d)\n", u, v);
	printf("o pai de %d eh %d e dfs_parent[u] eh %d\n", v, dfs_parent[v], dfs_parent[u]);*/
      // if(!(v == dfs_parent[u])){
      //printf("Achei ciclo em (%d, %d)\n", u, v);
      //comp_cycle[vez].push_back(vez);
      int raiz = u;
      raizes_ciclos.push_back(raiz);
      // printf("u eh %d, v eh %d, vez eh %d\n", u, v, vez);
      int u = -1;
      while(u != vez){
	u = pilha.top();
	//printf("vertice %d\n", u);
	belongsCycle[u] = nCycle;
	pilha.pop();
	comp_cycle[raiz].push_back(u);
      }
      nCycle++;
      // }      
    }
  }
  dfs_num[u] = VISITED;
}



int main(){
  while(scanf("%d", &n) != EOF){
    int v_cycle = 10004;
    nCycle = 1;
    AdjList.assign(n + 1, vi());
    AdjList2.assign(n + 1, vi());
    for(int u = 1; u <= n; u++){
      int v;
      scanf("%d", &v);
      AdjList[u].push_back(v);
      //printf("Adicionei (%d, %d) como aresta\n", u, v);
      //AdjList[v].push_back(u);
    }
    //agora vou detectar os ciclos
    dfs_num.assign(n+1, UNVISITED); dfs_parent.assign(n+1, 0);
    for(int i = 1; i <= n; i++){
      if(dfs_num[i] == UNVISITED){
	vez = i;
	pilha.push(vez);
	graphCheck(i);
      }
    }
    printf("vertices dos ciclos (%d) que irei comprimir:\n", (int) raizes_ciclos.size());
    for(int i = 0; i < (int) raizes_ciclos.size(); i++){
      printf("ciclo que tem vertice %d como raiz\n", raizes_ciclos[i]);
      for(int j = 0; j < (int) comp_cycle[raizes_ciclos[i]].size(); j++){
	printf("%d ", comp_cycle[raizes_ciclos[i]][j]);
      }
      puts("");
    }
    //agora vou construir o segundo grafo, sem ciclo
    for(int u = 1; u <= n; u++){
      if(belongsCycle[u]) continue;
      for(int j = 0; j < (int) AdjList[u].size(); j++){
	int v = AdjList[u][j];
	if(!belongsCycle[v]){//se o vertice v nao pertence a algum ciclo
	  AdjList2[u].push_back(v);
	  printf("To adicionando (%d, %d) como aresta\n", u, v);
	}else{//caso ele pertença, irei ligar ele a um vértice burro + numero do ciclo
	  printf("To adicionando (%d, %d) como aresta\n", u, v_cycle + belongsCycle[v]);
	  AdjList2[u].push_back(v_cycle + belongsCycle[v]);
	}
      }
    }
    /*altura = 0;
    monta_arvore(1, 1, 0);
    segmento = sqrt(altura);
    printf("segmento foi %d\n", segmento);
    // monta_super_pai(1, 1);
    int query;
    scanf("%d", &query);
    for(int i = 0; i < query; i++){
      int u, v;
      scanf("%d %d", &u, &v);
      int c = LCA(u, v);
      printf("%d\n", (nivel[u] - nivel[c]) + (nivel[v] - nivel[c]));
    }*/
    
  }
  return 0;
}
