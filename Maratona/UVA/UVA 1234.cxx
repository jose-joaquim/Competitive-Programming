#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

bool cmp(const iii &a, const iii &b){
	return a.first > b.first;	
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


int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int l = 0; l < ct; l++){
		int m, n;
		scanf("%d %d", &m, &n);
		vector<iii> EdgeList;
		int tot = 0;
		for(int i = 0; i < n; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(iii(w, ii(u-1, v-1)));
			tot += w;
		}
		
		sort(EdgeList.begin(), EdgeList.end(), cmp);
		
		int mst_cost = 0;
		UnionFind UF(m);
		
		for(int i = 0; i < n; i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n", tot-mst_cost);
	}
	return 0;
}

