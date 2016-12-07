//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2001
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

typedef map<string, int> msi;
typedef vector<string> vS;
typedef map<string, vS> msvS;
typedef vector<int> vi;

int main(int argc, char **argv)
{
	int ct, cs = 0;
	while(scanf("%d", &ct) != EOF){
		int E;
		string u, v;
		vector<vi> AdjList(ct);
		vector<string> topoSort;
		vector<bool> used(ct, false);
		map<string, int> sToInt;
		map<int, string> intToS;
		vector<int> inDegrees(ct, 0);
		for(int i = 0; i < ct; i++){
			fflush(stdin);
			cin >> u;
			sToInt[u] = i;
			intToS[i] = u;
		}
		scanf("%d", &E);
		for(int i = 0; i < E; i++){
			fflush(stdin);
			cin >> u >> v;
			AdjList[sToInt[u]].push_back(sToInt[v]);
			inDegrees[sToInt[v]]++;
		}
		priority_queue<int, vector<int>, greater<int> > pq;
		for(int i = 0; i < ct; i++){
			if(inDegrees[i] == 0){
				used[i] = true;
				pq.push(i);
			}				
		}
		while(!pq.empty()){
			int u = pq.top(); pq.pop();
			topoSort.push_back(intToS[u]);
			for(int i = 0; i < (int) AdjList[u].size(); i++){
				int v = AdjList[u][i];
				inDegrees[v]--;
			}
			for(int i = 0; i < ct; i++){
				if(inDegrees[i] == 0 && !used[i]){
					used[i] = true;
					pq.push(i);
				}
			}
		}
		
		printf("Case #%d: Dilbert should drink beverages in this order:", ++cs);
		for(int i = 0; i < (int) topoSort.size(); i++){
			cout << " " << topoSort[i];
		}
		printf(".\n\n");
	}
	return 0;
}

