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

int arr[] = {100, 20, 10, 5, 1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int aux = n / arr[i];
    ans += aux;
    n -= arr[i] * (n / arr[i]);
  }
  cout << ans << '\n';
  return 0;
}
