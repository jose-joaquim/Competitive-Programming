#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

#define INF 1000000000
#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi learn_values;
pair<int, int> combo;
int V, E;

int main(int argc, char **argv)
{
	int ct, aux, u, v;
	scanf("%d", &ct);
	for(int l = 1; l <= ct; l++){
		learn_values.clear();
		combo.first = 0;
		combo.second = 0;
		scanf("%d %d", &V, &E);
		for(int i = 0; i < V; i++){
			scanf("%d", &aux);
			learn_values.push_back(aux);
		}
		AdjList.assign(V, vi());
		for(int i = 0; i < E; i++){
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
		}
		while(AdjList[combo.second].size() > 0){
			int node = -1;
			int ln = 0;
			for(int i = 0; i < (int) AdjList[combo.second].size(); i++){
				int v = AdjList[combo.second][i];
				if(ln < learn_values[v]){
					ln = learn_values[v];
					node = v;
				}
			}
			combo.first += ln;
			combo.second = node;
		}		
		printf("Case %d: %d %d\n", l, combo.first, combo.second);
	}
	return 0;
}
