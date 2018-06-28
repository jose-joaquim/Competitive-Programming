#include <cstring>
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

  int n; cin >> n;

  if (n % 2 != 0) {
    cout << -1 << '\n';
  } else {
    int perm[n];
    memset(perm, -1, sizeof perm);

    for (int i = 0; i < n; i++) {
      perm[i] = i + 1;
    }

    for (int k = 1; k < n; k += 2) {
      swap(perm[k - 1], perm[k]);
    }  

    for (int x : perm) {
      cout << x << " ";
    } cout << '\n';
  }
  return 0;
}
