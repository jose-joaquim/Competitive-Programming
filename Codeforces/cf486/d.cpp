#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> ii;

const int MAXN = 2 * 1e5 + 2;

int n;
int arr[MAXN];

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  vector<int> res = {arr[0]};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 30; j++) {
      int lx = arr[i] - (1 << j);
      int rx = arr[i] + (1 << j);
      bool isl = binary_search(arr, arr + n, lx);
      bool isr = binary_search(arr, arr + n, rx);
      if (isl && isr && int(res.size()) < 3) {
        res = { lx, arr[i], rx };
      }
      if (isl && int(res.size()) < 2) {
        res = { lx, arr[i] };
      }
      if (isr && int(res.size()) < 2) {
        res = { arr[i], rx };
      }
    }
  }
  cout << (int)res.size() << '\n';
  for (int x : res) {
    cout << x << " ";
  } cout << '\n';
  return 0;
}
