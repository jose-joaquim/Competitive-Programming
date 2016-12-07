//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=195
#include <bits/stdc++.h>

#define MAX_V 38
#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int res[MAX_V][MAX_V], mf, f, s, t;              
int n, m, total_apps;
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge) {    
  if (v == s){
	f = minEdge; 
	return; 
  }else if(p[v] != -1){
	augment(p[v], min(minEdge, res[p[v]][v]));
	res[p[v]][v] -= f; 
	res[v][p[v]] += f;
  }      
}

void make_graph(string linha){
  string palavra;
  stringstream ss;
  ss << linha;
  ss >> palavra;
  int app = palavra[0] - 'A' + 1;
  res[s][app] = palavra[1] - '0';
  total_apps += palavra[1] - '0';
  //
  ss >> palavra;
  for(int i = 0; palavra[i] != ';'; i++){
	int computer = palavra[i] - '0' + 27;
	AdjList[app].push_back(computer);
	AdjList[computer].push_back(app);
	res[app][computer] = INF;
  }
}

int main(int argc, char **argv)
{
  s = 0; t = 37;
  string linha;
  while(getline(cin, linha)){
	//
	total_apps = 0;
	AdjList.assign(MAX_V, vi());
	memset(res, 0, sizeof res);
	//
	for(int i = 1; i <= 26; i++){
	  AdjList[s].push_back(i);
	  AdjList[i].push_back(s);
	}
	for(int i = 27; i < 37; i++){
	  AdjList[i].push_back(t);
	  AdjList[t].push_back(i);
	  res[i][t] = 1;
	}
	//
	make_graph(linha);
	while(getline(cin, linha) && linha.size()) make_graph(linha);
	//
	mf = 0;
	while (1){
	  f = 0;
	  bitset<MAX_V> vis; vis[s] = true;
	  queue<int> q; q.push(s);
	  p.assign(MAX_V, -1);
	  while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
		  int v = AdjList[u][j];
		  if (res[u][v] > 0 && !vis[v])
			vis[v] = true, q.push(v), p[v] = u;
		}
	  }
	  augment(t, INF);
	  if (f == 0) break;
	  mf += f;
	}
	if(mf == total_apps){
	  for(int i = 27; i < 37; i++){
		bool foi = false;
		for(int j = 1; j <= 26; j++){
		  if(res[i][j]){
			printf("%c", j + 'A' - 1);
			foi = true;
			break;
		  }
		}
		if(!foi) printf("_");
	  }
	  puts("");
	}else puts("!");
  }
  return 0;
}
