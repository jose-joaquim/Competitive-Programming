#include <bits/stdc++.h>
using namespace std;
 
typedef long long lli;
typedef long long unsigned llu;
 
inline llu sqr(lli x){ return x*x; }
 
const int N = 5e4 + 10;
 
int n;
int x[N], y[N];
map<pair<int, int>, int> mp;
vector<int> adj[N];
bool vis[N];
int cnt[2];
 
void dfs(int u, int c = 0){
  if(vis[u]) return;
  vis[u] = true;
  cnt[c]++;
  for(int v : adj[u]) dfs(v, !c);
}
 
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    mp[{x[i], y[i]}] = i;
  }
  for(int i = 0; i < n; i++){
    for(int dx = -5; dx <= 5; dx++){
      for(int dy = -5; dy <= 5; dy++){
	int sqr_dist = sqr(dx) + sqr(dy);
	pair<int, int> p(x[i] + dx, y[i] + dy);
	if(sqr_dist != 0 && sqr_dist <= 25 && mp.count(p)){
	  adj[i].push_back(mp[p]);
	}
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    cnt[0] = cnt[1] = 0;
    dfs(i);
    ans += min(cnt[0], cnt[1]);
  }
  cout << ans << endl;
  return 0;
}
