#include <set>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int count (multiset<int> &x) {
  int sum = 0;
  for (auto s : x) {
    sum += s;
  }
  return sum;
}

bool cmp(const ii &x, const ii &y) {
  return abs(x.second - x.first) - abs(y.second - y.first);
}

int main() {
  string number; cin >> number;
  vector<ii> p;
  int s_l = 0, s_r = 0;
  for (int i = 0; i <= 2; i++) {
    s_l += number[i] - 48;
    s_r += number[(int) number.size() - i - 1] - 48;
  }
  return 0;
}
