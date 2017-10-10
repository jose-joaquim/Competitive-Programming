//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1202
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1500;

char nn[100001];
long long fib[1500];
int t, sz;

int main(){
  int ct; scanf("%d", &ct);
  fib[1] = fib[2] = 1;
  for(int i = 3; i < 1500; i++){
    fib[i] = (fib[i - 1] + fib[i - 2])%1000;
  }
  while(ct--){
    //scanf("%d", &t);
    scanf("%s", nn);
    t = (int) strlen(nn);
    long long ans = 0;
    for(int i = 0; i < t; i++){
      ans *= 2;
      ans += (nn[i] - '0');
      ans %= MOD;
    }
    printf("%0.3lld\n", fib[ans]);
  }
  return 0;
}
