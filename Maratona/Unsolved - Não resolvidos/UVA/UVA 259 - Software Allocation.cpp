#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#include <bitset>
#include <sstream>

#define MAX_V 105
#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
int computer_used[10], vet_apps[26], total_apps;
int n, m;
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
	if (v == s){
		f = minEdge; 
		return; 
	}else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v])); // recursive
		res[p[v]][v] -= f; 
		res[v][p[v]] += f;
	}       // update
}

void make_graph(string linha){
	string palavra;
	stringstream ss;
	ss << linha;
	ss >> palavra;
	int app = palavra[0] - 'A' + 1;
	//
	if(!vet_apps[app - 1]){
		total_apps++;
	}else vet_apps[app - 1] = 1;
	//
	AdjList[s].push_back(app);
	res[s][app] += palavra[1];
	//
	ss >> palavra;
	for(int i = 0; palavra[i] != ';'; i++){
		int computer = palavra[i] + 27;
		AdjList[app].push_back(computer);
		res[app][computer] = INF;
		computer_used[palavra[i] - '0'] = 1;
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
		memset(computer_used, 0, sizeof computer_used);
		memset(vet_apps, 0, sizeof vet_apps);
		puts("oi");
		make_graph(linha);
		puts("eoq");
		while(getline(cin, linha) && linha.size()) make_graph(linha);
		puts("kk");
		for(int i = 0; i < 10; i++){
			if(computer_used[i]) AdjList[computer_used[i] + 27].push_back(t);
		}
		//
		mf = 0;
		while (1){
			f = 0;
			bitset<MAX_V> vis; vis[s] = true;            // we change vi dist to bitset!
			queue<int> q; q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == t) break;
				for (int j = 0; j < (int)AdjList[u].size(); j++) {  // we use AdjList here!
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
			printf("foi\n");
		}else puts("nao");
	}
	return 0;
}





