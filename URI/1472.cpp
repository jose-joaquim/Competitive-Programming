#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int p[n], soma[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", p + i);
    }
    soma[0] = p[0];
    for (int i = 1; i < n; i++) {
      soma[i] = p[i] + soma[i - 1];
    }
    for (int x : soma) {
      printf("%d ", x);
    } puts("");

    for (int i = 0; i < n; i++) {
      
    }
  }
  return 0;
}
