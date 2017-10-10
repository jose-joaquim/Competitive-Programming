//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1537
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 100001;
const int MOD = 1000000009;

long long dp[MAXN];
int n;

void solve(){
  dp[3] = 1;
  for(int i = 4; i < MAXN; i++){
    dp[i] = (dp[i - 1] * i * 1LL)%MOD;    
  }
}

int main(){
  memset(dp, -1, sizeof dp);
  solve();
  while(scanf("%d", &n) && n){
    printf("%lld\n", dp[n]);
  }
  return 0;
}
