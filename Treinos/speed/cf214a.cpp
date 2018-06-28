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

  long long n, m; cin >> n >> m;

  long long ans = 0;
  for (long long a = 0; a <= 10000; a++) {
    for (long long b = 0; b <= 10000; b++) {
      if ((a * a) + b == n && a + (b * b) == m) {
        //printf("%lld %lld\n", a, b);
        ans++;
      }
    }
  }

  //cout << 
  cout << ans << '\n';
  return 0;
}
