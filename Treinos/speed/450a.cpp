#include <deque>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define len(x) ((int)x.size())

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif

  int n, m; cin >> n >> m;
  deque<pair<int, int> > child(n);
  for (int i = 0; i < n; i++) {
    int u; cin >> u;
    child[i] = make_pair(u, i + 1);
  }


  int last = -1;
  while(!child.empty()) {
    //cout << child.size() << endl;;
    //child[0].first -= m;
    if ((child[0].first -= m) <= 0) {
      last = child[0].second;
      child.pop_front();
    } else {
      child.push_back(child[0]);
      child.pop_front();
    }
  }

  cout << last << '\n';
  return 0;
}
