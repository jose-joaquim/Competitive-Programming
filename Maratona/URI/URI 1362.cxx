#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <bitset>

#define INF 1000000000
#define MAX_V 40

using namespace std;

typedef vector<int> vi;

int res[40][40], mf, f, s, t;
vi p;
vector<vi> AdjList;
int n, m, ct;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
  if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
  else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
                         res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

int main(int argc, char **argv)
{
	scanf("%d", &ct);
	map<string, int> my;
	my["XXL"] = 1; my["XL"] = 2; my["L"] = 3; 
	my["M"] = 4; my["S"] = 5; my["XS"] = 6;
	for(int q = 0; q < ct; q++){
		scanf("%d %d", &n, &m);
		AdjList.assign(m+10, vi());
		memset(res, 0, sizeof res);
		s = 0, t = m+7;
		for(int i = 1; i <= 6; i++){
			res[0][i] = n/6;
		}
		for(int i = 7; i < 7 + m; i++){
			string a, b;
			cin >> a >> b;
			res[my[a]][i] = 1;
			res[my[b]][i] = 1;
		}
		for(int i = 7; i <= m + 7; i++){
			res[i][7 + m] = 1;
		}
		
	  mf = 0;                                              // mf stands for max_flow
	  while (1) {              // O(VE^2) (actually O(V^3E) Edmonds Karp's algorithm
		f = 0;
		// run BFS, compare with the original BFS shown in Section 4.2.2
		vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
		p.assign(MAX_V, -1);           // record the BFS spanning tree, from s to t!
		while (!q.empty()) {
		  int u = q.front(); q.pop();
		  if (u == t) break;      // immediately stop BFS if we already reach sink t
		  for (int v = 0; v < MAX_V; v++)                 // note: this part is slow
			if (res[u][v] > 0 && dist[v] == INF)
			  dist[v] = dist[u] + 1, q.push(v), p[v] = u;
		}
		augment(t, INF);     // find the min edge weight `f' along this path, if any
		if (f == 0) break;      // we cannot send any more flow (`f' = 0), terminate
		mf += f;                 // we can still send a flow, increase the max flow!
	  }

		puts(mf == m ? "YES" : "NO");
		
	}
	return 0;
}

