#include <deque>
#include <stack>
#include <set>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main() {
  int n; cin >> n;
  stack<ii> first, second;
  vector<ii> shows;
  first.push(ii(0, 0));
  second.push(ii(0, 0));
  for (int i =0 ; i < n; i++) {
    int u, v; cin >> u >> v;
    shows.push_back(ii(u, v));
  }
  sort(shows.begin(), shows.end());
  
  for (int i = 0 ; i < n; i++) {
    ii front = shows[i];
    int u = front.first, v = front.second;
    //printf("looking %d %d\n", u, v);
    if (u >= first.top().second) {
      first.push(ii(u, v + 1));
    } else if (u >= second.top().second) {
      second.push(ii(u, v + 1));
    } else {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}
