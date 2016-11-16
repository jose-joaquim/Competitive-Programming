#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> adjlist;

adjlist adj;
int mark[1010];
int grau[1010];
bool mat[1010][1010];
vi path;
bool pode = true;
int dest = 0;

void DFS(int s){
	//printf("s=%d\n",s);
	mark[s]=1;
	for(int i=0; i < (int) adj[s].size(); i++){
		int u = adj[s][i];
		if(mat[s][u] && pode && !mark[u]){
			mat[s][u]=mat[u][s]=false;
			DFS(u);
		} 
	}
	pode = false;
	//printf("s=%d\n",s);
	path.push_back(s);
}

void DFS2(int s){
	mark[s]=1;
	for(int i=0; i < (int) adj[s].size(); i++){
		int u = adj[s][i];
		if(mat[s][u] && !mark[u]){
			mat[s][u]=mat[u][s]=false;
			DFS2(u);
		} 
	}
}

void init(int v){
	adj.assign(v+1,vi());	
	memset(mark,0,sizeof mark);
	memset(mat,false,sizeof mat);
	memset(grau,0,sizeof grau);
	path.clear();
	pode = true;
}

bool comp(int v, int u){
	return grau[v] < grau[u];
	}

int main(int argc, char **argv)
{
	int n, m;
	while(scanf("%d %d",&n,&m) && n){
		init(n);
		for(int i=0; i < m; i++){
			int a, b;
			scanf("%d %d",&a,&b);
			mat[a][b]=true;
			mat[b][a]=true;
			adj[a].push_back(b);
			adj[b].push_back(a);
			grau[a]++; grau[b]++;
		}
		for(int i=1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), comp);
		DFS(1);
		dest = path[0];
		memset(mark,0,sizeof mark);
		/*for(int i=0; i < (int)path.size(); i++)
			printf("dest[%d] = %d ",i,path[i]);
		printf("\n");*/
		pode = true;
		DFS2(dest);
		if(mark[1]){
				printf("S\n");
		}else{
			printf("N\n");
		}
	}	
	return 0;
	
}

