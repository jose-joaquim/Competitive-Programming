#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int x, y; cin >> x >> y;
  if (x == y) {
    cout << "=" << '\n';
    return 0;
  }
  
  if (x == 1) {
    cout << "<" << '\n';
  } else if (y == 1) {
    cout << ">" << '\n';
  } else if (x == 2) {
    if (y == 4) {
      cout << "=" << '\n';
    } else if (y == 3) {
      cout << "<" << '\n';
    } else {
      cout << ">" << '\n';
    }
  } else if (y == 2) {
    if (x == 4) {
      cout << "=" << '\n';
    } else if (x == 3) {
      cout << ">" << '\n';
    } else {
      cout << "<" << '\n';
    }
  } else {
    if (x < y) {
      cout << ">" << '\n';
    } else {
      cout << "<" << '\n';
    }
  }
  return 0;
}
  
