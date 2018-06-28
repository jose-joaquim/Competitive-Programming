#include <limits>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int a, c;
  while((cin >> a >> c) && a != 0 && c != 0) {
    int h[c];
    int ans = 0;
    int minv = numeric_limits<int>::max();
    for (int i = 0; i < c; i++) {
      cin >> h[i];
      minv = min(minv, h[i]);
    }

    int s = 0, t = 0;
    while (t < c) {
      while (t < c && h[t + 1] >= h[t]) {
        t++;
      }
      
      if (t == c) {
        ans += h[--t] - h[s];
        break;
      } else {
        
      
        ans += h[t] - h[s];
        while(t < c && h[t] >= h[t + 1]) {
          t++;
        }
        
        if (t >= c)
          break;
      
        s = t;
      }
    }

    cout << ans + (a - h[c - 1]) << endl;
  }
  return 0;
}
