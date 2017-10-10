//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2005

#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

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

ll numPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans++; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}


bool isPrime(ll N) { 
  if (N <= _sieve_size) return bs[N];   
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;                
}        

int main(){
  ll n;
  sieve(10000000);
  while(scanf("%lld", &n) != EOF){
    printf("%lld\n", isPrime(n) ? 0 : (n - numDiv(n) - EulerPhi(n) + 1));
  }
  return 0;
}
