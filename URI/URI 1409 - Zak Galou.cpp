//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1409


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> adjlist;
typedef pair<int,int> ii;

int n, m, g, k;
const int INF = 999999999;
int peso[1001];

adjlist adj;
adjlist adjm;

int mem[1001];

int em[1001];
int dm[1001];
int pai[1001];
int dist[1001];
vi path;

void init(){
  adj.assign(1001,vi());
  adjm.assign(1001,vi());
  memset(peso,0,sizeof peso);
  memset(mem,-1,sizeof mem);
  memset(em,0,sizeof mem);
  memset(dm,0,sizeof dm);  
  memset(pai,0,sizeof pai);
  path.clear();
}

void dijkstra(int s){
  ii par = ii(peso[s],s);
  pai[s]=s;
  dist[s]=peso[s];
  priority_queue<ii,vector<ii>, greater<ii> > fila;
  fila.push(par);
  while(!fila.empty()){
    ii ft = fila.top();
    fila.pop();
    int v = ft.second;
    int w = ft.first;
    if (w > dist[v]) continue;
    
    for(int i=0; i < (int)adj[v].size(); i++){
      int u = adj[v][i];
      if (dist[u] > w + peso[u]){
		dist[u] = w + peso[u];
		fila.push(ii(w+peso[u],u));
		pai[u]=v;
      }
    }
  }
}

void build_path(int d){
  while(pai[d] != d){
    //printf("%d ",d);
    path.push_back(d);
    d = pai[d];
  }
  path.push_back(1);
  //printf("1\n\n");
}

int dp(int w, int i){  
  if (i > m) return INF;
  if (w <= 0) return 0;
  
  if (mem[w][i] != -1) return mem[w][i];
  
  int nao = dp(w,i+1);
  int sim = em[i] + dp(w - dm[i],i);
  
  return mem[w][i]=min(sim,nao);
}

int main(){
  while(scanf("%d %d %d %d",&m,&n,&g,&k) && n){
    int a, b;
    printf("m=%d n¨=%d g=%d k=%d\n",m,n,g,k);
    init();
    for(int i=1; i <= m; i++){
      scanf("%d %d",&a,&b);
      em[i]=a;
      dm[i]=b;
    }
    
    for(int i=0; i < g; i++){
      scanf("%d %d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);      
    }

    for(int i=1; i <= k; i++){
      scanf("%d %d",&a,&b);
      peso[a]+=b;
      adjm[a].push_back(b);
    }

    for(int i=0; i <= n; i++) dist[i]=INF;
    printf("bug\n");
    dijkstra(1);    
    if (dist[n]==INF){
      printf("-1\n");
    }else{
      build_path(n);
      int ans = 0;
      for(int i=0; i < (int)path.size(); i++){
		int v = path[i];
		for(int j=0; j < (int)adjm[v].size(); j++){
		  int u = adjm[v][j];
		  printf("u=%d vd%d\n",u,u);
		  ans += dp(u,1);
		}
      }
      printf("%d\n",ans);
    }

  }
  return 0;
}
