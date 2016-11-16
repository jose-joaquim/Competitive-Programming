#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<double, double> ii;
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
	for(int i = 0; i < ct; i++){
		int V;
		scanf("%d", &V);
		vector<ii> pairXY;
		vector<pair<double, ii> > EdgeList;
		for(int l = 0; l < V; l++){
			double x, y;
			scanf("%lf %lf", &x, &y);
			pairXY.push_back(ii(x, y));
		}
		for(int l = 0; l < V; l++){
			for(int j = 0; j < l; j++){
				double length = dist(pairXY[l], pairXY[j]);
				EdgeList.push_back(iii(length, ii(l, j)));
			}
		}
		
		sort(EdgeList.begin(), EdgeList.end());
		int sz = (int) EdgeList.size();
		double mst_cost = 0;
		UnionFind UF(V);
		for(int l = 0; l < sz; l++){
			iii front = EdgeList[l];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%.2lf\n", (mst_cost/100));
	}
	return 0;
}

