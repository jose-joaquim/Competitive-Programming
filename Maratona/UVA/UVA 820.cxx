#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#include <bitset>


#define MAX_V 105
#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int res[MAX_V][MAX_V], mf, f, s, t;                          // global variables
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

int main(int argc, char **argv)
{
	int cs = 0;
	while(scanf("%d", &n) && n){
		AdjList.assign(n+1, vi());
		memset(res, 0, sizeof res);
		scanf("%d %d %d", &s,  &t, &m);
		for(int i = 0; i < m; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			res[u][v] += w;
			res[v][u] += w;
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		
		 mf = 0;
		  while (1) {
			f = 0;
			bitset<MAX_V> vis; vis[s] = true;            // we change vi dist to bitset!
			queue<int> q; q.push(s);
			p.assign(MAX_V, -1);
			while (!q.empty()) {
			  int u = q.front(); q.pop();
			//  printf("u eh %d\n", u);
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
		printf("Network %d\nThe bandwidth is %d.\n\n", ++cs, mf);
	}
	return 0;
}

