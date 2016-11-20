//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1088

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
	for(int l = 0; l < ct; l++){
		int N, M;
		//int mst_cost = 0, fixed_cost = 0;
		scanf("%d", &N);
		vector<ii> towns;//, highways;
		vector<iii> EdgeList;//, FixedEdges;
		UnionFind UF1(N);
		for(int i = 0; i < N; i++){
			double x, y;
			scanf("%lf %lf", &x, &y);
			towns.push_back(ii(x, y));
		}
		
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				double length = dist(towns[i], towns[j]);
				EdgeList.push_back(iii(length, ii(i, j)));
			}
		}
		
		scanf("%d", &M);
		
		for(int i = 0; i < M; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			if(!UF1.isSameSet(x-1, y-1)){
				UF1.unionSet(x-1, y-1);
			}
		}
		
		sort(EdgeList.begin(), EdgeList.end());
		
		int szEdge = (int) EdgeList.size();
		bool go = true;
		
		for(int i = 0; i < szEdge; i++){
			iii front = EdgeList[i];
			if(!UF1.isSameSet(front.second.first, front.second.second)){
				printf("%d %d\n", (int)front.second.first+1, (int)front.second.second+1);
				go = false;
				UF1.unionSet(front.second.first, front.second.second);
			}
		}
		puts("");
	}
	return 0;
}


