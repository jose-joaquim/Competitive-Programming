#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

#define INF 1000000000

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


int main(int argc, char **argv)
{
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		vector<iii> EdgeList;
		int maximo = -INF;
		int cont = 0;
		EdgeList.push_back(iii(1, ii(x, y)));
		maximo = max(maximo, max(x, y));
		cont++;
		while(scanf("%d", &x) && (x != -1)){
			scanf("%d", &y);
			EdgeList.push_back(iii(1, ii(x, y)));
			maximo = max(maximo, max(x, y));
			cont++;
		}
		vector<bool> visited(cont, false);
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(maximo+1);
		int ans = cont;
		for(int i = 0; i < cont; i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				ans--;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

