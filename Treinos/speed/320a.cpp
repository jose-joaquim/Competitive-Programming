#include <set>
#include <deque>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define len(x) ((int)x.size())

set<string> numbers;
string arr[3];
string number;
bool ans;

void form(string now, int i) {
  //cout << now << " " << i << endl;
  if (i > 9) return;
  for (int j = 0; j < 3; j++) {
    string aux = now + arr[j];
    if (aux == number) {
      cout << "YES\n";
      ans = true;
      return;
    }
    if (len(aux) < 9) {
      form(aux, len(aux));
    }
  }
}

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  ans = false;
  arr[0] = "1";
  arr[1] = "14";
  arr[2] = "144";
  cin >> number;
  form("", 0);
  if (!ans) {
    cout << "NO\n";
  }
  return 0;
}
