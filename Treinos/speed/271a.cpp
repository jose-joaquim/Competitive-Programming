#include <deque>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define len(x) ((int)x.size())

bool alldiff(int year) {
  vector<bool> dig(9, 0);
  while (year != 0) {
    int last = year % 10;
    year /= 10;
    if (dig[last]) {
      return false;
    } else {
      dig[last] = true;
    }
  }

  return true;
}

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  int year; cin >> year;

  year++;
  while (true) {
    if (alldiff(year)) break;
    year += 1;
  }
  cout << year << '\n';
  return 0;
}
