//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1602


#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <bitset>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int dp[2000005];
vi primes;
int _sieve_size;
bitset<20000010> bs;

bool isPrime(ll N) {               
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}            

void sieve(ll upperbound) {    
  _sieve_size = upperbound + 1;                
  bs.set();                                            
  bs[0] = bs[1] = 0;                                
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);
} }

ll numDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;          
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;                                         
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);                          
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;
  return ans;
}

bool hiperprimo(int x){
  if(isPrime(x)){
    return true;
  }else{
    if(fmod(sqrt(x), 1) == 0){
      return isPrime(numDiv(x));
    }else{
      return false;
    }
  }
  return false;
}

void pre(){
  dp[0] = dp[1] = 0;
  dp[2] = 1;
  for(int i = 3; i < 2000005; i++){
    dp[i] = dp[i-1] + hiperprimo(i);
  }
}

int main(){
  memset(dp, 0, sizeof dp);
  sieve(20000000);
  pre();
  int n;
  while(scanf("%d", &n) != EOF){
    printf("%d\n", dp[n]);
  }
  return 0;
}
