//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2847

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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

int m, n;

int main(int argc, char **argv)
{
	while(scanf("%d %d", &n, &m) && (n || m)){
		vector<iii> EdgeList;
		//int w_matrix[n][m];
		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(iii(w, ii(u, v)));
			//w_matrix[u][v] = w;
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(n);
		vector<int> cycles;//(n, INT_MIN);
		for(int i = 0; i < m; i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				UF.unionSet(front.second.first, front.second.second);
			}else{
				//int set = UF.findSet(front.second.first);
				cycles.push_back(front.first);
				//cycles[set] = max(cycles[set], front.first);
				//printf("aresta (%d, %d) iria formar um ciclo e ele esta no grupo %d\n", front.second.first, front.second.second, UF.findSet(front.second.first));
			}
		}
		int length = (int) cycles.size();
		if(length){		
			printf("%d", cycles[0]);
			for(int i = 1; i < length; i++){
				//if(cycles[i] != INT_MIN){
					printf(" %d", cycles[i]);
				//}
			}
			printf("\n");
		}else puts("forest");
	}
	return 0;
}

