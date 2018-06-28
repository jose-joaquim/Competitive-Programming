#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  string n; cin >> n;
  int ans = 0;
  for (int i = 0; i < (int) n.size(); i++) {
    if (n[i] - '0' == 4 || n[i] - '0' == 7) {
      ans += 1;
    }
  }
  cout << ((ans == 4 || ans == 7) ? "YES" : "NO") << '\n';
  return 0;
}
