//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1082

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

vi dfs_num;
vector<vi> AdjList;
string ans;
int nC;

void dfs(int u){
	ans += u+97;
	nC++;
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int) AdjList[u].size(); i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == UNVISITED){
			dfs(v);
		}
	}
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int k = 1; k <= ct; k++){
		int n, m;
		scanf("%d %d", &n, &m);
		AdjList.assign(n, vi());
		for(int i = 0; i < m; i++){
			char a, c;
			cin >> a >> c;
			int u = a - 97;
			int v = c - 97;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		
		printf("Case #%d:\n", k);
		
		dfs_num.assign(n, UNVISITED);
		int numCC = 0;
		for(int i = 0; i < n; i++){
			if(dfs_num[i] == UNVISITED){
				ans = "";
				nC = 0;
				numCC++;
				dfs(i);
				sort(ans.begin(), ans.end());
				for(int x = 0; x < nC; x++) printf("%c,", ans[x]);
				printf("\n");
			}
		}
		
		printf("%d connected components\n", numCC);
		puts("");		
	}
	return 0;
}

