#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

bool has(vi v, int e) {
	for (int i = 0; i < (int) v.size(); i++)
		if (v[i] == e)
			return true;
	return false;
}

int main(int argc, char **argv)
{
	int M;
	cin >> M;
	while(M--){
		vector<vi> AdjList;
		printf("\n");
		int N;
		cin >> N;
		AdjList.assign(N, vi());
		for(int i = 0; i < N; i++){
			int qtd;
			int a;
			cin >> qtd;
			for(int j = 0; j < qtd; j++){
				scanf("%d", &a);
				a--;
				if (a < N) {
					if (!has(AdjList[i], a))
						AdjList[i].push_back(a);
					if (!has(AdjList[a], i))
						AdjList[a].push_back(i);
				}
			}
		}
		vi color(N, 1e9);		
		int ans = 0;
		bool isBipartite;
		for(int i = 0; i < N; i++){
			if(color[i] != 1e9) continue;
			
			int colorCount[2] = {0, 0};
			queue <int> q;
			q.push(i);
			color[i] = 0;
			colorCount[0]++;
			isBipartite = true;
			
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(int j = 0; j < (int)AdjList[u].size(); j++){
					int v = AdjList[u][j];
					if(color[v] == 1e9){
						color[v] = 1 - color[u];
						colorCount[color[v]]++;
						q.push(v);
					}else if(color[v] == color[u]){
						isBipartite = false;
					}					
				}			
			}
			if(isBipartite) ans += max(colorCount[0], colorCount[1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
