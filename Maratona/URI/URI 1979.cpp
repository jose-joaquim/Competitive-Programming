#include <cstdio>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> AdjList;
int n;

int main(){
  while(scanf("%d", &n) && n){
    AdjList.assign(n + 1, vi());
    for(int pp = 0; pp < n; pp++){
      int u; cin >> u;
      cin.ignore();
      stringstream ss; string palavra, linha;
      getline(cin, linha);
      ss << linha;
      while(ss >> palavra){
	int num = stoi(palavra);
	AdjList[u].push_back(num);
	AdjList[num].push_back(u);
      }
    }
    vi dist(n+1, INF); dist[1] = 0;
    queue<int> q; q.push(1);
    bool isBipartite = true;
    while(!q.empty() & isBipartite){
      int u = q.front(); q.pop();
      for(int i = 0; i < (int) AdjList[u].size(); i++){
	int v = AdjList[u][i];
	if(dist[v] == INF){
	  dist[v] = 1 - dist[u];
	  q.push(v);
	}else if(dist[v] == dist[u]){
	  isBipartite = false;
	  break;
	}
      }      
    }
    printf(isBipartite ? "SIM\n" : "NAO\n");
  }
  return 0;
}
