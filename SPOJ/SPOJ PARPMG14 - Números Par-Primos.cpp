//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: http://br.spoj.com/problems/PARPMG14/

#include <bits/stdc++.h>

using namespace std;

int main(){
  long long a, b;
  while(scanf("%lld %lld", &a, &b)){
    if(!a && !b) break;
    int l = ceil(sqrt(a)), r = sqrt(b);
    long long ans = b - a + 1 - (r - l + 1);
    printf("%lld\n", ans);
  }
  return 0;
}
