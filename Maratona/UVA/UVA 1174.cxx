#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
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
	for(int ct = 0; ct < eoq; ct++){
		int m, n;
		scanf("%d %d", &m, &n);
		vector<iii> EdgeList;
		map<string, int> values;
		int myint = 0;
		for(int i = 0; i < n; i++){
			string u, v;
			int c;
			cin >> u >> v >> c;
			if(!values.count(u)) values[u] = myint++;
			if(!values.count(v)) values[v] = myint++;
			EdgeList.push_back(iii(c, ii(values[u], values[v])));
		}
		
		sort(EdgeList.begin(), EdgeList.end());
		
		UnionFind UF(m);
		int mst_cost = 0;
		for(int i = 0; i < n; i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		
		printf("%d\n", mst_cost);
		if(ct < eoq - 1) printf("\n");
	}
	return 0;
}

