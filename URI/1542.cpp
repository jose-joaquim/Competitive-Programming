#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  // 3 (q) <-> x
  // 5 (p) <-> (x - 16(d))
  double q, d, p;
  while (scanf("%lf", &q) && q != 0) {
    scanf("%lf %lf", &d, &p);
    double x = ((q) * d) / (p - q);
    int ans = (x + d) * q;
    if (ans == 1)
      puts("1 pagina");
    else
      printf("%d paginas\n", ans);
  }
  return 0;
}
