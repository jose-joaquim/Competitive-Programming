#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const double EPS = 1e-7;

int main() {
  int n; cin >> n;
  if (!n) {
    cout << 0 << endl;
    return 0;
  }
  n++; n %= 360;
  int i;
  for (i = 1; i <= 360; i++) {
    if (360.0 / (double)i == (double)n) break;
  }
  if (n % 2 == 0) {
    cout << 180 / i << endl;
  }else 
    cout << (int)(360.0 / (double)i) << endl;
  /*if (!n) {
    cout << 0 << endl;
    return 0;
  }
  double l = 0, r = 360;
  double mid;
  n++;
  n %= 360;
  while (abs(l - r) >= EPS) {
    mid = (l + r) / 2.0;
    //cout << mid << " " << 360.0 / mid <<  endl;
    if (360.0 / mid > n) {
      l = mid;
    } else if (360.0 / mid < n) {
      r = mid;
    } else break;
  }
  if (180 % (int)(mid) == 0) {
    cout << 180 / ((int) mid) << endl;
  } else 
    cout << (int)360.0 / mid << endl;*/
  return 0;
}
