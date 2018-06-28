#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n;
  long long quad[101];
  for (int i = 0; i < 101; i++) {
    quad[i] = i * i;
  }
  while (cin >> n) {
    if (n < 0) {
      cout << "NO";
      goto prox;
    }
    for (int i = 0; i * i <= n; i++) {
      for (int j = 0; j * j <= n; j++) {
        if (quad[i] + quad[j] == n) {
          cout << "YES";
          goto prox;
        }
      }
    }
    cout << "NO";
    
  prox:
    cout << '\n';
  }
  return 0;
}
