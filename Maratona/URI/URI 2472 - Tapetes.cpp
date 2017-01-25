//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2472
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll l, n; scanf("%lld %lld", &l, &n);
  ll sub = l - n + 1;
  printf("%lld\n", sub*sub + (n - 1));
  return 0;
}
