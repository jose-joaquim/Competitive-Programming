//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1764

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

double dist(ii a, ii b){
 return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

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

int m, n;

int main(int argc, char **argv)
{
	while(scanf("%d %d", &m, &n) && (m || n)){
		vector<iii> EdgeList;
		for(int i = 0; i < n; i++){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			EdgeList.push_back(iii(z, ii(x, y)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(m);
		int mst_cost = 0;
		for(int i = 0; i < n; i++){
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

