#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;


int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif

  int n, k; cin >> n >> k;
  vector<int> arr;
  map<int, int> wtf;
  for (int i = 0; i < n; i++) {
    int u; cin >> u;
    if (wtf.find(u) == wtf.end()){
      arr.push_back(u);
      wtf[u] = 1;
    } else 
      wtf[u] += 1;
  }

  sort(arr.begin(), arr.end());

  int ans = 0;
  for (int i = 1; i < int(arr.size()); i++) {
    if (arr[i] > arr[i - 1]) {
      if (arr[i] <= arr[i - 1] + k) {
        ans += wtf[arr[i - 1]];
      }
    }
  }
  cout << n - ans << '\n';
  return 0;
}
