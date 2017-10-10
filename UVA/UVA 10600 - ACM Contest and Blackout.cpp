//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541
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
typedef pair<int, ii> iii;

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
		int n, m;
		scanf("%d %d", &n, &m);
		vector<iii> EdgeList;
		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(iii(w, ii(u, v)));
		}
		
		int mst_cost = 0, scd_mst = 0;
		vector<ii> blocked;
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(n+1);
		int resp = 1000000000;
		
		for(int i = 0; i < m; i++){
			iii front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
				blocked.push_back(EdgeList[i].second);
			}
		}
		
		for(int j = 0; j < (int) blocked.size(); j++){
			scd_mst = 0;
			UnionFind UF1(n+1);
			for(int i = 0; i < m; i++){
				iii front = EdgeList[i];
				if((front.second.first == blocked[j].first) && (front.second.second == blocked[j].second)) continue;
				if(!UF1.isSameSet(front.second.first, front.second.second)){
					scd_mst += front.first;
					UF1.unionSet(front.second.first, front.second.second);
				}
			}
			if(scd_mst >= mst_cost){
				resp = min(resp, scd_mst);
			}
			
		}
		
		
		printf("%d %d\n", mst_cost, resp);
	}
	return 0;
}

