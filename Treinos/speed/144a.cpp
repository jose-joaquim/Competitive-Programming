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

  int n; cin >> n;
  int arr[n];
  for (int &x : arr) {
    cin >> x;
  }

  int mx = 0, mn = 101;
  int mxp = -1, mnp = 101;
  for (int i = 0; i < n; i++) {
    int x = arr[i];
    if (x > mx) {
      mxp = i + 1;
      mx = x;
    }
    if (x <= mn) {
      mnp = i + 1;
      mn = x;
    }
  }

  cout << mxp - 1 + n - mnp - (mnp < mxp);
  cout << '\n';
  
  return 0;
}
