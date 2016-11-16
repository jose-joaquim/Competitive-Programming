#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <map>
#include <queue>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, pair<int, char> > aa;
typedef vector<aa> vaa;

int n;
string from, to;
map<string, int> stringInt;
map<int, string> intString;
vector<vaa> AdjList;

struct comp
{
	bool operator()(const aa& lhs, const aa& rhs) const
	{
		if(lhs.second.first == rhs.second.first){
			return lhs.first < rhs.first;
		}
		return lhs.second.first < rhs.second.first;
	}
};

int main(int argc, char **argv)
{
	while(scanf("%d", &n) && n){
		AdjList.assign(n, vaa());
		cin >> from >> to;
		int qtd = 0;
		for(int i = 0; i < n; i++){
			string u, v, w;
			cin >> u >> v >> w;
			int sz = (int) w.size();
			if(!stringInt.count(u)){
				stringInt[u] = qtd;
				intString[qtd] = u;
				qtd++;
			}
			if(!stringInt.count(v)){
				stringInt[v] = qtd;
				intString[qtd] = v;
				qtd++;
			}
			
			AdjList[stringInt[u]].push_back(aa(stringInt[v], make_pair(sz, w[0])));
			AdjList[stringInt[v]].push_back(aa(stringInt[u], make_pair(sz, w[0])));
		}
		if(!stringInt[from] || !stringInt[to]){
			puts("impossivel");
			continue;
		}
		vi dist(qtd, INF);
		priority_queue<aa, vector<aa>, comp> pq;
		dist[stringInt[from]] = 0;
		pq.push(aa(0, make_pair(stringInt[from], '-')));
		while(!pq.empty()){
			aa front = pq.top(); pq.pop();
			int d = front.first; int u = front.second.first;
			if(d > dist[u]) continue;
			char tal = front.second.second;
			//cout << intString[u];
			//printf(" tem %d filhos\n", (int) AdjList[u].size());
			for(int j = 0; j < (int) AdjList[u].size(); j++){
				aa v = AdjList[u][j];
				//if(tal != v.second.second) puts("asd");
				if(tal != v.second.second && dist[v.first] > v.second.first + dist[u]){
					dist[v.first] = v.second.first + dist[u];
					pq.push(aa(dist[v.first], make_pair(v.first, v.second.second)));
				}
			}
		}
		/*for(int i = 0; i < n; i++) printf("%d ", dist[i]);
		puts("");*/
		if(dist[stringInt[to]] == INF){
			puts("impossivel");
		}else printf("%d\n", dist[stringInt[to]]);
	}
	return 0;
}
