#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<50000010> bs;
vi primes;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }


void sieve(ll upperbound) {   
  _sieve_size = upperbound + 1;   
  bs.set();               
  bs[0] = bs[1] = 0;    
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {

      for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
      primes.push_back((int)i);
    } }   

ll numPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans++; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

int main(){
  sieve(50000000);
  long long n;
  scanf("%I64d", &n);
  printf("%I64d\n", numPF(n));
  return 0;
}
