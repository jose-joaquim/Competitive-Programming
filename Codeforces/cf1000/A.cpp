#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define len(x) ((int)x.size())

int main() {
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  int n; cin >> n;
  multiset<string> list;
  for (int i = 0; i < n; i++) {
    string u; cin >> u;
    list.insert(u);
  }
  for (int i = 0; i < n; i++) {
    string u; cin >> u;
    if (list.find(u) != list.end()) {
      list.erase(list.find(u));
    }
  }
  cout << list.size() << '\n';
  return 0;
}
