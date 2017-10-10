//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1338
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <limits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const ll MAX = 20000000000;

ll _sieve_size;
bitset<100000100> bs;
vi primes;
vi mu;
unsigned long long n;

bool isPrime(ll N) {          
  if (N <= _sieve_size) return bs[N];            
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}

void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;                   
  bs.set();
  mu.assign(550000, 1);
  mu[1] = 1;
  bs[0] = bs[1] = 0;                              
  for (ll i = 2; i <= _sieve_size; i++){
    if (bs[i]) {
      for (ll j = i; j <= _sieve_size; j += i){
        if((j % (i * i)) == 0){
          mu[j] = 0;
        }else mu[j] *= -1;
        bs[j] = 0;
      }
      primes.push_back((int)i);
      mu[i] = -1;
    }
  }
}

ll howMany(ll r){
  ll ret = 0;
  for(ll i = 1; i * i <= r; i++){
    ret += mu[i] * r/(i*i);
  }
  return ret;
}

unsigned long long search(){
  unsigned long long l = 0, mid, r = 4e10;
  while(l < r){
    mid = (l + r)/2;
    ll ms = howMany(mid);
    if(howMany(mid) >= n){
      r = mid;
    }else l = mid + 1;
  }
  return l;
}

int main(){
  int T; scanf("%d", &T);
  sieve(550000);
  while(T--){
    cin >> n;
    cout << search() << endl;
  }
  return 0;
}
