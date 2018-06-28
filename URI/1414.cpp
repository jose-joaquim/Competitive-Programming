#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int t, n;
  while ((cin >> t >> n) && t != 0) {
    int soma = 0;
    for (int i = 0; i < t; i++) {
      string nome; int p;
      cin >> nome >> p;
      soma += p;
    }
  
    cout << (3 * n) - soma << '\n';
  }
  return 0;
}
