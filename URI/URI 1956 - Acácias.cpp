//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1956

#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<double, double> ii;
typedef pair<double, ii> iii;

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

int N;

int main(int argc, char **argv)
{
	scanf("%d", &N);
	vector<pair<long long, ii> > EdgeList;
	for(int i = 1; i <= N - 1; i++){
		int k;
		scanf("%d", &k);
		for(int q = 0; q < k; q++){
			int j; long long cij;
			scanf("%d %lld", &j, &cij);
			EdgeList.push_back(make_pair(cij, ii(i, j)));
		}
	}
		long long mst_cost = 0;
		UnionFind UF(N+1);
		sort(EdgeList.begin(), EdgeList.end());
		long long num = 0;
		
		for(int i = 0; i < (int) EdgeList.size(); i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				num++;
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%lld %lld\n", N-num, mst_cost);
	return 0;
}

