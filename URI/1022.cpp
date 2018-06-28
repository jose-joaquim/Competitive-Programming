#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int T; scanf("%d", &T);
  while(T--) {
    int n1, n2, d1, d2; char op;
    scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
    int r1, r2;
    switch(op) {
    case '+':
      r1 = n1 * d2 + n2 * d1;
      r2 = d1 * d2;
      break;
    case '-':
      r1 = n1 * d2 - n2 * d1;
      r2 = d1 * d2;
      break;
    case '*':
      r1 = n1 * n2;
      r2 = d1 * d2;
      break;
    case '/':
      r1 = n1 * d2;
      r2 = n2 * d1;
      break;
    }
    int cmm = gcd(abs(r1), abs(r2));
    printf("%d/%d = %d/%d\n", r1, r2, r1 / cmm, r2 / cmm);
  }
  return 0;
}
