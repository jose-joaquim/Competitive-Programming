//Author/Autor: pin3da - https://github.com/pin3da/Programming-contest/blob/master/solved/URI/1479%20Help%20your%20Commander/solution.cc
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1286

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi dist;
vector<vii> AdjList;
int n, m;

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

UnionFind *UF;

void dijkstra(){
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(0, 0));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int u = front.second; int d = front.first;
		if(d > dist[u]) continue;
		for(int j = 0; j < (int) AdjList[u].size(); j++){
			ii v = AdjList[u][j];
			if(dist[u] + v.second < dist[v.first]){
				UF->unionSet(u, v.first);
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}



int main(int argc, char **argv)
{
	while(scanf("%d %d", &n, &m) && (n || m)){
		AdjList.assign(n, vii());
		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			AdjList[u-1].push_back(ii(v-1, w));
		}
		UF = new UnionFind(n);
		dist.assign(n, INF);
		dist[0] = 0;
		dijkstra();
		//printf("IASND %d\n", dist[2]);
		/*int q;
		scanf("%d", &q);
		for(int i = 0; i < q; i++){
			char c;
			int u, v, w;
			fflush(stdin);
			scanf("%c", &c);
			//puts("AE");
			switch(c){
				case 'I': 
					break;
				case 'P':
					scanf("%d", &v);
					printf("%d\n", dist[v-1]);
					break;
				case 'R': 
					break;
			}
		}*/
	}
	return 0;
}

