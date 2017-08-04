//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1754

#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int T; scanf("%d", &T);
  while(T--){
    unsigned long long x, y; scanf("%llu %llu", &x, &y);
    if(y > x) swap(x, y);

    unsigned long long k = x / y;

    if(x % y != 0 || x == y) k++;

    printf("%llu\n", k);
  }
  return 0;
}
