//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=950

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <stdlib.h>

#define INF 1000000000

using namespace std;

typedef vector<string> vS;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef map<string, vS> msvS;
typedef pair<string, string> pSS;

msvS AdjList;
map<string, string> p;
int aux = 0;

void printPath(string u, string source){
	if(u == source){
		printf("%c", source[0]);
		return; 
	}
	printPath(p[u], source);
	printf("%c", u[0]);
}

int main(int argc, char **argv)
{
	int ct;
	cin >> ct;
	for(int l = 0; l < ct; l++){
		int m, n;
		cin >> m >> n;
		AdjList.clear();
		p.clear();
		for(int i = 0; i < m; i++){
			string u, v;
			cin >> u >> v;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		vector<pSS> search;
		for(int i = 0; i < n; i++){
			string u, v;
			cin >> u >> v;
			search.push_back(pSS(u, v));
		}
		for(int i = 0; i < n; i++){
			map<string, int> dist;
			dist[search[i].first] = 0;
			queue<string> q; q.push(search[i].first);
			while(!q.empty()){
				string u = q.front(); q.pop();
				for(int j = 0; j < (int) AdjList[u].size(); j++){
					string v = AdjList[u][j];
					if(!dist.count(v)){
						dist[v] = dist[u] + 1;
						p[v] = u;
						q.push(v);
					}
				}
			}
			printPath(search[i].second, search[i].first);
			printf("\n");
		}
		if(l < ct-1) printf("\n");
	}
	return 0;
}

