#include <limits>
#include <deque>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

#define len(x) ((int)x.size())

typedef vector<int> vi;

int n;
deque<int> arr;

int main() {
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u; cin >> u;
    arr.push_back(u);
  }

  int idx = 0, t = 0;
  deque<int> tozero(n, 0);
  for (int i = 0; i < n; i++) {
    if (arr[i] - t <= 0) {
      cout << i + 1<< '\n';
      return 0;
    }
    int voltas = ceil(arr[i] - t / n);
    tozero[i] = voltas;
    t++;
  }
  int ans = numeric_limits<int>::max(), p = n + 1;
  for (int i = 0; i < n; i++) {
    if (tozero[i] < ans) {
      p = i;
      ans = tozero[i];
    }
  }
  cout << p + 1 << '\n';
  return 0;
}
