#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stdlib.h>

#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pair<int, ii> > viii;
typedef pair<int, pair<int, int> > iiMatrix;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int n, m, cap;

bool valid(int r, int c){
	return (r < 0 || r >= n || c < 0 || c > cap);
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &n, &m) != EOF){
		vi prices;
		int q;
		vector<vii> AdjList(n);
		for(int i = 0; i < n; i++){
			int p;
			cin >> p;
			prices.push_back(p);
		}
		for(int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			AdjList[u].push_back(ii(v, w));
			AdjList[v].push_back(ii(u, w));
		}
		cin >> q;
		for(int l = 0; l < q; l++){
			int u, v;
			cin >> cap >> u >> v;
			int values[n][cap+1];
			for(int i = 0; i < n; i++){
				for(int j = 0; j <= cap; j++){
					values[i][j] = INF;
				}
			}
			priority_queue<iiMatrix, vector<iiMatrix>, greater<iiMatrix> > pq; 
			pq.push(iiMatrix(0, ii(u, 0)));
			values[u][0] = 0;
			while(!pq.empty()){
				iiMatrix u = pq.top(); pq.pop();
				int d = u.first; ii posAtual = u.second;
				if(d > values[posAtual.first][posAtual.second]) continue;
				
				if(!valid(posAtual.first, posAtual.second + 1)){
					values[posAtual.first][posAtual.second+1] = values[posAtual.first][posAtual.second] + prices[posAtual.first];
					pq.push(iiMatrix(values[posAtual.first][posAtual.second+1], ii(posAtual.first, posAtual.second + 1)));
				}
				for(int i = 0; i < (int) AdjList[posAtual.first].size(); i++){
					ii v = AdjList[posAtual.first][i];
					int from = posAtual.first;
					int to = v.first;
					int length = v.second;
					int fuel = posAtual.second;
					if(fuel >= length){
						if(values[to][fuel-length] > values[from][posAtual.second]){
							values[to][fuel-length] = values[from][posAtual.second];
							pq.push(iiMatrix(values[to][fuel-length], ii(to, fuel-length)));	
						}
					}
				}
			}
			int resp = INF;
			for(int i = 0; i <= cap; i++){
				resp = min(resp, values[v][i]);
			}
			if(resp == INF){
				printf("impossible\n");
			}else printf("%d\n", resp);
		}
	}	
	return 0;
}

