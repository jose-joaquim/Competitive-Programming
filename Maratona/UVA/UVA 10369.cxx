#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <cmath>

using namespace std;

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, ii> iii;

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


int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int l = 0; l < ct; l++){
		int s, p;
		vector<iii> EdgeList;
		vector<ii> pares;
		scanf("%d %d", &s, &p);
		for(int i = 0; i < p; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			pares.push_back(ii(u, v));
		}
		for(int i = 0; i < p; i++){
			for(int j = 0; j < i; j++){
				double length = dist(pares[i], pares[j]);
				EdgeList.push_back(iii(length, ii(i, j)));
			}
		}
		
		int cc = p;
		double mst_cost = 0.0;
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(p);
		
		for(int i = 0; i < (int) EdgeList.size() && cc != s; i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost = front.first;
				UF.unionSet(front.second.first, front.second.second);
				cc--;
			}
		}
		printf("%.2lf\n", mst_cost);
	}
	return 0;
}

