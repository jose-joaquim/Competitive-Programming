//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1512
#include <cstdio>
#include <iostream>

using namespace std;

int n, a, b;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
int mmc(int a, int b){ return a * (b / gcd(a, b)); }

int main(){
  while(scanf("%d %d %d", &n, &a, &b) && n){
    int ans = 0;
    ans += n/a;
    ans += n/b;
    ans -= n/(mmc(a, b));
    printf("%d\n", ans);
  }
  return 0;
}
