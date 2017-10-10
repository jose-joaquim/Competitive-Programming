#include <bitset>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int a, b, n;
vector<int> y;
ll _sieve_size;
bitset<10000010> bs;
vi primes;
int dp[10][82][10][10];

void sieve(ll upperbound) {       
  _sieve_size = upperbound + 1;                   
  bs.set();                                             
  bs[0] = bs[1] = 0;                                    
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i); 
} }

bool isPrime(ll N) {
  if(N == 0 || N == 1) return false;
  if (N <= _sieve_size) return bs[N];  
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;                   
}  

void splitNumber(int x){
  y.clear();
  while(x != 0){
    y.push_back(x % 10);
    x /= 10;
  }
  reverse(y.begin(), y.end());
  n = (int) y.size();
}

int solve(int i, int sum, int leftmost_lo, int leftmost_hi){
  if(i == n){
    if(leftmost_lo <= leftmost_hi && isPrime(1LL * sum)){
      return 1;
    }else return 0;
  }

  int &ret = dp[i][sum][leftmost_lo][leftmost_hi];

  if(ret != -1) return ret;
  
  int result = 0;

  for(int d = 0; d <= 9; d++){
    int lo = leftmost_lo;
    int hi = leftmost_hi;
    if(d < y[i] && i < lo) lo = i;
    if(d > y[i] && i < hi) hi = i;
    result += solve(i + 1, sum + d, lo, hi);
  }

  return ret = result;
}

int main(){
  int c; scanf("%d", &c);
  sieve(1000000);
  while(c--){
    scanf("%d %d", &a, &b);
    memset(dp, -1, sizeof dp);
    splitNumber(a - 1);
    int ans = solve(0, 0, n, n);

    memset(dp, -1, sizeof dp);
    splitNumber(b);
    int ans2 = solve(0, 0, n, n) - ans;
    printf("%d\n", ans2);
  }
  return 0;
}
