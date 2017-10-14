//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1492

#include <cmath>
#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

typedef long long ll;

long long dp[60][60][60];//[2];
long long a, b;
int bits;

void countBits(ll x){
  bits = 0;
  while(x){
    bits++;
    x >>= 1;
  }
}

/*ll solve(int i, ll qtd, ll numero, const ll &x, bool acendi){
  if(numero == x){
    //printf("%d %lld %lld %lld\n", i, qtd, numero, x);
    //printf("             _ %d\n", qtd);
    return acendi ? qtd : 0;
  }
  
  if(i > bits || numero > x){
    //puts("               voltando");
    return 0;//(acendi) ? -1: 0;
  }

  //printf("%d %lld %lld %lld %d\n", i, qtd, numero, x, acendi);

  
  ll result = acendi ? qtd : 0;

  ll &ret = dp[i][qtd][numero == 0 ? 1 : (int)log2(numero)];//[acendi];
  if(ret != -1){
    //printf("          ja conheco (%d %lld %d) = %lld\n", i, qtd, acendi, ret);
    return ret;
  }
  
  ll novo_numero = numero + (ll)pow(2, i);

  //result += solve(i + 1, qtd + 1, novo_numero, x) + solve(i + 1, qtd, numero, x);

  //printf("(add qtd %lld) vou acender bit %d\n", qtd, i);
  result += solve(i + 1, qtd + 1, novo_numero, x, true);
  //printf("nao vou acender bit %d\n", i);
  result += solve(i + 1, qtd, numero, x, false);
  return ret = result;
}*/

inline bool bitAtivado(const ll &x, int i){
  return (x >> i) & 1LL;
}

ll solve(const ll &x, int i, int qtd, bool acendi){
  if(i == -1)
    return qtd;

  long long ans = 0;

  ll &ret = dp[i][qtd][acendi];
  
  if(ret == -1){
    ret = solve(x, i - 1, qtd, !((x >> i) & 1LL) && acendi);
    if(!acendi || bitAtivado(x, i)){
      ret += solve(x, i - 1, qtd + 1, ((x >> i) & 1LL) && acendi);
    }
  }

  
  return ret;
}

long long count(ll x){
  countBits(x);
  //printf("%lld tem %d bits\n", x, bits);
  memset(dp, -1, sizeof dp);
  return solve(x, 55, 0, true);//solve(0, 0, 0, x, false);
}

int main(){
  while(scanf("%lld %lld", &a, &b) != EOF){
    //bits = 5;
    //printf("%lld\n", solve(0, 0, 0, 20, false));
    ll ans1 = count(b);
    ll ans2 = count(a - 1);
    //printf("count b %lld count a - 1 %lld\n", ans1, ans2);
    printf("%lld\n", ans1 - ans2);
    //printf("%lld\n", count(b) - count(a - 1));
  }
  return 0;
}
