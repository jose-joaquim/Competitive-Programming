#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi idades, dfs_num;
int n, m, i;

int dfs(int u, int ageRoot){
	int atingido = ageRoot ? 100000 : idades[u];
	dfs_num[u] = VISITED;
	for(int i = 0; i < (int) AdjList[u].size(); i++){
		int v = AdjList[u][i];
		if(dfs_num[v] == UNVISITED){
			atingido = min(atingido, dfs(v, 0));
		}
	}
	
	return atingido;
}

int main(int argc, char **argv)
{
	while(scanf("%d %d %d", &n, &m, &i) != EOF){
		AdjList.assign(n, vi());
		dfs_num.assign(n, UNVISITED);
		idades.clear();
		for(int j = 0; j < n; j++){
			int u; 
			scanf("%d", &u);
			idades.push_back(u);
		}
		for(int j = 0; j < m; j++){
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[v-1].push_back(u-1);
		}
		/*for(int j = 0; j < n; j++){
			printf("%d ", atingido[j]);
		}
		printf("\n");*/
		for(int q = 0; q < i; q++){
			cin.ignore();
			char c;
			int ans;
			int u, v;
			scanf("%c", &c);
			switch(c){
				case 'P':
					scanf("%d", &u);
					dfs_num.assign(n, UNVISITED);
					ans = dfs(u - 1, 1);
					if(ans == 100000){
						puts("*");
					}else printf("%d\n", ans);
					break;
				case 'T':
					scanf("%d %d", &u, &v);
					swap(AdjList[u-1], AdjList[v-1]);
					for(int a = 0; a < n; a++){
						for(int b = 0; b < (int) AdjList[a].size(); b++){
							if(AdjList[a][b] == u - 1){
								AdjList[a][b] = v - 1;
							}else if(AdjList[a][b] == v - 1){
								AdjList[a][b] = u - 1;
							}						
						}
					}
					break;
			}	
		}
	}
	return 0;
}

