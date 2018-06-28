#include <algorithm>
#include <deque>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define len(x) ((int)x.size())

bool isdiv(deque<int> &dig) {

  if (dig[len(dig)] != 0) {
    return false;
  }

  int sum = 0;
  for (int x : dig) {
    sum += x;
  }
  
  return sum % 9 == 0;
}

inline void printans(deque<int> &dig) {
  for (int &x : dig) {
    cout << x;
  } cout << '\n';
}

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif

  int n; cin >> n;
  deque<int> dig(n);
  for (int &x : dig) {
    cin >> x;
  }

  sort(dig.rbegin(), dig.rend());
  if (isdiv(dig)) {
    printans(dig);
  } else {
    while(!dig.empty()) {
      dig.pop_front();
      if (isdiv(dig)) {
        break;
      }
    }

    if (dig.empty()) {
      cout << "-1\n";
    } else {
      bool zero = true;
      for (int x : dig) {
        if (x != 0) {
          zero = false;
          break;
        }
      }
      if (zero) cout << "0\n";
      else {
        printans(dig);
      }
    }
  }
  return 0;
}
