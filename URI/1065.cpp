#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int ans = 0;
  for (int i = 0; i < 5; i++) {
    int u; cin >> u;
    if (u < 0) u *= -1;
    if (u % 2 == 0) {
      ans += 1;
    }
  }
  printf("%d valores pares\n", ans);
  return 0;
}
