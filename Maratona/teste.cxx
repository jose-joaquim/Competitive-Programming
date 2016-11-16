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
	while(scanf("%d", &ct) != EOF){
		vector<pair<int, ii> > EdgeList;
		EdgeList.push_back(make_pair(10, ii(0, 1)));
		EdgeList.push_back(make_pair(28, ii(1, 2)));
		EdgeList.push_back(make_pair(38, ii(0, 2)));
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(3);
		int mst_cost = 0;
		for(int i = 0; i < 3; i++){
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

