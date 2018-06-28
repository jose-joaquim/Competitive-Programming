#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  ll n, m, a, b; cin >> n >> m >> a >> b;

  ll ans1 = n % m * b;
  ll ans2 = (m - n % m) * a;
  cout << min(ans1, ans2) << endl;
  
  return 0;
}
