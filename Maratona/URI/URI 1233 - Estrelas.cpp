//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1233
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
  int n;
  while (scanf("%d", &n) != EOF){
    int ans = n;
  
    for (unsigned int i = 2; i*i <= n; i++) {
      if (n % i == 0) {
        ans /= i;
        ans *= i-1;
      }
      while (n % i == 0)
        n /= i;
    }
       
    if (n > 1) {
      ans /= n;
      ans *= n-1;
    }   

    ans /= 2;
    cout << ans << endl;
  }
}
