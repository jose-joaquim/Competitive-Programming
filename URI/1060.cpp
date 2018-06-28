#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int ans = 0;
  for (int i = 0; i < 6; i++) {
    double u; scanf("%lf", &u);
    if (u > 0.0) {
      ans += 1;
    }
  }

  printf("%d valores positivos\n", ans);
  return 0;
}
