#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
	int V, E, u, v, TC;
	vector<vi> AdjList;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &V, &E);
		AdjList.assign(V, vi());
		for(int i = 0; i < E; i++){
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		vi color(V, 1e9);
		bool isPartite;
		int ans = 0;
		for(int s = 0; s < V; s++){
			if(color[s] != 1e9) continue;
			
			isPartite = true;
			int colorC[2] = { 0, 0 };
			queue<int> q; q.push(s);
			color[s] = 0;
			colorC[0]++;
			
			while(!q.empty()){
				u = q.front(); q.pop();
				for(int i = 0; i < (int)AdjList[u].size(); i++){
					int v = AdjList[u][i];
					if(color[v] == 1e9){
						color[v] = 1 - color[u];
						colorC[color[v]]++;
						q.push(v);
					}else if(color[u] == color[v]){
						isPartite = false;
						break;
					}
				}		
			}
			
			if(isPartite){
				ans += (colorC[0] > 0 && colorC[1] > 0) ?
						min(colorC[0], colorC[1]) :
						max(colorC[0], colorC[1]);
					}else
					ans = -1;
		}
		printf("%d\n", ans);
	}	
	return 0;
}
