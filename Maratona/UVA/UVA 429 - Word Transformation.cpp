//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=370

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;

vector<string> words;
map<string, int> MapAux;
vector<pair<string, string> > search;
vector<vi> AdjList;

bool diff(string &c, string &a){
	int length = 0;
	if(c.size() != a.size()) return false;
	for(int i = 0; i < (int) c.size(); i++){
		if(c[i] != a[i]) length++;
		if(length > 1) return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	while(ct--){
		words.clear();
		AdjList.clear();
		search.clear();
		string s, a;
		int sizeMap = 0, sizeSearch = 0;
		while(cin >> s && s[0] != '*'){
			words.push_back(s);
			MapAux[s] = sizeMap;
			sizeMap++;
		}
		
		AdjList.assign(sizeMap, vi());
		string linha;
		getline(cin,linha);
		getline(cin,linha);
		while((int) linha.size() > 0){
			stringstream ss(linha);
			ss >> s >> a;
			search.push_back(make_pair(s, a));
			sizeSearch++;
			getline(cin,linha);
		}
		
		int m = (int) words.size();
		for(int i = 0; i < m; i++){
			for(int j = i + 1; j < m; j++){
				if(diff(words[i], words[j])){//diferem de apenas uma letra, então são ligados por uma arestra
					AdjList[MapAux[words[i]]].push_back(MapAux[words[j]]);
					AdjList[MapAux[words[j]]].push_back(MapAux[words[i]]);
				}
			}
		}
		for(int i = 0; i < sizeSearch; i++){//faz a BFS aqui dentro
			vi dist(sizeMap, INF); dist[MapAux[search[i].first]] = 0;
			queue<int> q;
			q.push(MapAux[search[i].first]);
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(int i = 0; i < (int) AdjList[u].size(); i++){
					int v = AdjList[u][i];
					if(dist[v] == INF){//ainda nao foi visitado
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
			cout << search[i].first << " " << search[i].second;
			if(dist[MapAux[search[i].second]] - dist[MapAux[search[i].first]] == INF){
				printf(" %d\n", -1);
			}else printf(" %d\n", dist[MapAux[search[i].second]] - dist[MapAux[search[i].first]]);
		}
		if(ct) printf("\n");
	}
	return 0;
}

