#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

const ll MAXC = 1e12;

ll l, r;
vector<vector<ll> > mat;
ll _sieve_size;
bitset<10000010> bs;
vi primes;   

void sieve(ll upperbound) {          
  _sieve_size = upperbound + 1;                   
  bs.set();                                       
  bs[0] = bs[1] = 0;                              
  for (ll i = 2; i <= _sieve_size; i++){
    if (bs[i]){
      for (ll j = i * i; j <= _sieve_size; j += i)
        bs[j] = 0;
      primes.push_back((int)i);
    }
  }
}

void solve(){
  mat.assign((int)primes.size() + 1, vector<ll>());
  for(int i = 0; i < (int) primes.size(); i++){
    for(ll j = primes[i]; j <= MAXC; j *= primes[i]){
      mat[i].push_back(j);
    }
  }
}

ll howMany(ll X, bool inclusive){
  ll ans = 0;
  for(int i = 0; i < (int) mat.size(); i++){
    if(primes[i] >= X && !inclusive) break;
    if(primes[i] > X) break;
    for(int j = 1; j < (int) mat[i].size(); j++){
      if(mat[i][j] >= X && !inclusive) break;
      if(mat[i][j] > X){
        break;
      }else ans++;
    }
  }
  return ans;
}

int main(){
  sieve(10000000);
  solve();
  int cs; scanf("%d", &cs);
  while(cs--){
    scanf("%lld %lld", &l, &r);
    printf("%lld\n", howMany(r, true) - howMany(l, false));
  }
  return 0;
}
