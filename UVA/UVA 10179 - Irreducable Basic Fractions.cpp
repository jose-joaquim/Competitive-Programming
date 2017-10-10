//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=975

#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;   
vi primes;  

void sieve(ll upperbound) {         
  _sieve_size = upperbound + 1;     
  bs.set();                         
  bs[0] = bs[1] = 0;                
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);  
} }   

ll EulerPhi(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = N;  
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans -= ans / PF;           
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans -= ans / N;                   
  return ans;
}

int main(){
  ll n;
  sieve(10000000);
  while(scanf("%lld", &n) && n != 0){
    printf("%lld\n", EulerPhi(n));
  }
  return 0;
}
