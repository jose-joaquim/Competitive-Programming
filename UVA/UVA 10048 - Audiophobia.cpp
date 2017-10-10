//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=989

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

#define INF 1000000000
#define VISITED 1
#define UNVISITED -1

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

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

vector<int> weights;
vector<int> visited;
vector<vector<ii> > AdjList;
int ini, fim, resp;
bool canGo;

void dfs(int u, int ans){
	//printf("to no vertice %d ANS NO MOMENTO EH %d\n", u, ans);
	for(int i = 0; i < (int) AdjList[u].size(); i++){
		ii v = AdjList[u][i];
		if(weights[v.first] == -INF){
			//printf("alcancei %d com %d\n", v.first, v.second);
			weights[v.first] = max(ans, v.second);
			if(v.first == fim){
				resp = weights[v.first];
			}else{
				dfs(v.first, weights[v.first]);
			}
		}
	}
}

int main(int argc, char **argv)
{
	int C, S, Q;
	int casos = 0;
	bool linha = false;
	while(scanf("%d %d %d", &C, &S, &Q) && (C || S || Q)){
		vector<iii> EdgeList;
		vector<ii> queries;
		if(linha){
			printf("\n");
		}else linha = true;
		for(int i = 0; i < S; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(iii(w, ii(u-1, v-1)));
		}
		for(int i = 0; i < Q; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			queries.push_back(ii(u-1, v-1));
		}
		
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(C);
		AdjList.assign(C, vector<ii>());
		weights.assign(C, -INF);
		for(int i = 0; i < S; i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				UF.unionSet(front.second.first, front.second.second);
				AdjList[front.second.first].push_back(ii(front.second.second, front.first));
				AdjList[front.second.second].push_back(ii(front.second.first, front.first));
			}
		}
		
		printf("Case #%d\n", ++casos);
		for(int ct = 0; ct < Q; ct++){
			weights.assign(C, -INF);
			ini = queries[ct].first;
			fim = queries[ct].second;
			resp = INF;
			dfs(queries[ct].first, -1);
			if(resp == INF){
				printf("no path\n");
			}else{
				printf("%d\n", resp);
			}
			//system("pause");
		}
	}
	return 0;
}

