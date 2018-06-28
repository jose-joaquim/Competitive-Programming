#include <map>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> ii;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  //set<ii> team;
  map<int, int> team;
  for (int i = 0; i < n; i++) {
    int u; cin >> u;
    //team.insert(ii(u, i+1));
    team[u] = i + 1;
  }
  if ((int)team.size() >= k) {
    cout << "YES" << '\n';
    int cnt = 0;
    for (auto x : team) {
      cout << x.second << " ";
      if (++cnt == k) {
        break;
      }
    } cout << '\n';
  } else {
    cout << "NO\n";
  }
  return 0;
}
