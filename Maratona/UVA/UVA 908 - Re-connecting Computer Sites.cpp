//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=849

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

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


int main(int argc, char **argv)
{
	int ct;
	bool ans = false;
	while(scanf("%d", &ct) != EOF){
		if(!ans){
			ans = true;
		}else{
			printf("\n");
		}
		int tc = 0;
		vector<pair<int, pair<int, int> > > EdgeList;
		for(int i = 0; i < ct-1; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			tc += w;
		}
		printf("%d\n", tc);
		
		int k;
		scanf("%d", &k);
		for(int i = 0; i < k; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(make_pair(w, ii(u, v)));
		}
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(make_pair(w, ii(u, v)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(k + m);
		int mst_cost = 0;
		for(int i = 0; i < k + m; i++){
			pair<int, ii> front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n", mst_cost); 
	}
	return 0;
}

