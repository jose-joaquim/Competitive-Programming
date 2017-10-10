//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1348


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

#define VISITED 1 
#define UNVISITED -1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
int C, P, SCCVertex[20015];
vi dfs_num, dfs_low, S, visited;
int V, E, dfsNumberCounter;
int numSCC;

int no(int i){
	return -1 * i;
}

int index(int i){
	return i >= 0 ? i : P - i;
}

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for(int j = 0; j < (int) AdjList[u].size(); j++){
		int v = AdjList[u][j];
		if(dfs_num[v] == UNVISITED){
			tarjanSCC(v);
		}
		if(visited[v]){
			dfs_low[u] = min(dfs_low[v], dfs_low[u]);
		}
	}
	
	if(dfs_low[u] == dfs_num[u]){
		numSCC++;
		while(1){
			int v = S.back(); S.pop_back(); visited[v] = 0;
			SCCVertex[v] = numSCC;
			if(u == v) break;
		}
	}
}

int main(int argc, char **argv)
{
	//int cs = 0;
	while(scanf("%d %d", &C, &P) && (C || P)){
		//printf("caso %d\n", ++cs);
		//fflush(stdout);
		AdjList.assign(20015, vi());
		//SCCVertex.assign(P+50, -1);
		for(int i = 0; i < C; i++){
			int a, b, c, d;
			cin >> a >> b;
			if(a || b){
				if(a == 0) a = b;
				if(b == 0) b = a;
				//printf("a eh %d index(no(a)) eh %d\n", index(a), index(no(a)));
				//printf("b eh %d index(no(b)) eh %d\n", index(b), index(no(b)));
				AdjList[index( no(a))].push_back(b);
				//puts("k");
				AdjList[index( no(b))].push_back(a);
				//puts("kk");
			}
			cin >> c >> d;
			//puts("passei");
			if(c || d){
				if(c == 0) c = d;
				if(d == 0) d = c;
				AdjList[c].push_back(index( no(d)));
				AdjList[d].push_back(index( no(c)));
			}
			//puts("again");
		}
		//puts("oi");
		
		dfs_low.assign(20015, 0);
		dfs_num.assign(20015, UNVISITED); 
		visited.assign(20015, 0);
		for(int i = 1; i <= P; i++){
			if(dfs_num[index(i)] == UNVISITED){
				tarjanSCC(i);
			}
			if(dfs_num[index(no(i))] == UNVISITED){
				tarjanSCC(index(no(i)));
			}
		}
		bool ans = true;
		for(int i = 1; i <= P; i++){
			if(SCCVertex[index(i)] == SCCVertex[index(no(i))]){
				ans = false;
			}
		}
		puts(ans ? "yes" : "no");
	}
	return 0;
}

