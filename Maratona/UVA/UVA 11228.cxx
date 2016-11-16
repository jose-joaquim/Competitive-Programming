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
	int eoq;
	scanf("%d", &eoq);
	for(int ct = 1; ct <= eoq; ct++){
		int n;
		double r;
		scanf("%d %lf", &n ,&r);
		vector<ii> pairXY;
		vector<pair<double, ii> > EdgeList;
		for(int i = 0; i < n; i++){
			double x, y;
			scanf("%lf %lf", &x, &y);
			pairXY.push_back(ii(x, y));
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				double length = dist(pairXY[i], pairXY[j]);
				EdgeList.push_back(iii(length, ii(i, j)));
			}
		}
		
		
		sort(EdgeList.begin(), EdgeList.end());
		int sz = (int) EdgeList.size();
		UnionFind UF_same(n);
		double mst_cost_same = 0, mst_cost_diff = 0, states = n;
		
		for(int i = 0; i < sz; i++){
			pair<double, ii> front = EdgeList[i];
			if(!UF_same.isSameSet(front.second.first, front.second.second)){
				if(front.first <= (double) r){
					mst_cost_same += front.first;
					states--;
				}else{
					mst_cost_diff += front.first;
				}
				UF_same.unionSet(front.second.first, front.second.second);
			}
		}
		
		printf("Case #%d: %d %d %d\n", ct, (int)states, (int)round(mst_cost_same), (int)round(mst_cost_diff));
	}
	return 0;
}

