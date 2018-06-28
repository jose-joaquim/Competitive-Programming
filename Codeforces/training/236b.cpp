#include <unordered_map>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long div(long long n) {
  //cout << n << " tem ";
  int nd = 0;

  long long aux = n;
  for (long long i = 1; i * i <= n; i++) {
    if (aux % i == 0) {
      nd++;
      if(aux / i != i) {
        nd++;
      }
    }
  }

  /*if (aux > 1)
    nd++;*/
  
  //cout << nd << " divisores\n";
  return 1LL * nd;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int a, b, c; cin >> a >> b >> c;
  long long ans = 0;
  unordered_map<long long, long long> divisors;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {      
        if (divisors.find(i * j * k) == divisors.end()) {
          long long gt = div(i * j * k);
          divisors[i * j * k] = gt;
          ans += gt;
        } else {
          ans += divisors[i * j * k]; 
        }
        //ans += gt;
        ans %= 1073741824;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
