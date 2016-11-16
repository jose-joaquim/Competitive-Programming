#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>

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


int main(int argc, char **argv)
{
	int eoq;
	scanf("%d", &eoq);
	for(int ct = 1; ct <= eoq; ct++){
		int n, m, a;
		scanf("%d %d %d", &n, &m, &a);
		vector<iii> EdgeList;
		UnionFind UF(n);
		
		int mst_cost = a*n;//a*n;
		int airports = n;
		for(int i = 0; i < m; i++){
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			EdgeList.push_back(iii(c, ii(x-1, y-1)));
		}
		
		sort(EdgeList.begin(), EdgeList.end());
		
		for(int i = 0; i < (int) EdgeList.size(); i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				if(front.first >= a){
					//mst_cost -= front.first;
					//mst_cost += a;
				}else{
					mst_cost += front.first;
					mst_cost -= a;
					airports--;
					UF.unionSet(front.second.first, front.second.second);
				}
			}
		}
		printf("Case #%d: %d %d\n", ct, mst_cost, airports);
	}
	return 0;
}



