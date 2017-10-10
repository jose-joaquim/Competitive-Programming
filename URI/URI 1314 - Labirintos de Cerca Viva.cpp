//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1314

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <map>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int r, c, q;
vector<vi> AdjList;
map<ii, bool> ans;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCount, dfsRoot, rootChildren;

class UnionFind{
	private: vi p, rank;
	public:
		UnionFind(int N){ 
			rank.assign(N, 0);
			p.assign(N, 0);
			for(int i = 0; i < N; i++){
				p[i] = i;
			}
		}
		int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }
		void unionSet(int i, int j){
			if(!isSameSet(i, j)){
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y]) p[y] = x;
				else{				  p[x] = y;
									  if(rank[x] == rank[y]) rank[y]++; }
			}
		}
};

UnionFind *UF;

void findBridges(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCount++;
	for(int j = 0; j < (int) AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED){
			dfs_parent[v] = u;
			if(dfsRoot == u) rootChildren++;
			
			findBridges(v);
			
			if(dfs_low[v] >= dfs_num[u]){
				articulation_vertex[u] = true;
			}
			if(dfs_low[v] > dfs_num[u]){
				UF->unionSet(u, v);
			}
			
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
			
		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}	
	}
}

int main(int argc, char **argv)
{
	while(scanf("%d %d %d", &r, &c, &q) && (r || c || q)){
		UF = new UnionFind(r);
		ans.clear();
		AdjList.assign(r, vi());
		dfsNumberCount = 0;
		dfs_num.assign(r, UNVISITED);
		dfs_low.assign(r, 0);
		dfs_parent.assign(r, 0);
		articulation_vertex.assign(r, 0);
		for(int i = 0; i < c; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[u-1].push_back(v-1);
			AdjList[v-1].push_back(u-1);
		}
		for(int i = 0; i < r; i++){
			if(dfs_num[i] == UNVISITED){
				dfsRoot = i; rootChildren = 0; findBridges(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		for(int i = 0; i < q; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			puts(UF->isSameSet(u-1, v-1) ? "Y" : "N");
		}
		puts("-");
	}
	return 0;
}
