#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int par, impar, pos, neg;

int main() {
  for (int n = 0; n < 5; n++) {
    int i; scanf("%d", &i);
    if (i > 0) {
      pos += 1;
    } else if (i < 0) {
      neg += 1;
    }

    if (i % 2 == 0) {
      par += 1;
    } else impar += 1;
  }

  printf("%d valor(es) par(es)\n", par);
  printf("%d valor(es) impar(es)\n", impar);
  printf("%d valor(es) positivo(s)\n", pos);
  printf("%d valor(es) negativo(s)\n", neg);
  return 0;
}
