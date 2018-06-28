#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int n;
vector<ii> consultas;

bool cmp(const ii &x, const ii &y) {
  if (x.second == y.second) {
    return x.first < y.first;
  } else {
    return x.second < y.second;
  }
}

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v; cin >> u >> v;
    consultas.push_back({u, v});
  }

  sort(consultas.begin(), consultas.end(), cmp);

  /*for (auto x : consultas) {
    cout << x.first << " " << x.second << endl;
  }*/

  int ans = 1;
  int look = consultas[0].second;
  for (int i = 1; i < n; i++) {
    if (consultas[i].first >= look) {
      ans++;
      look = consultas[i].second;
    }
  }

  cout << ans << '\n';
  return 0;
}
