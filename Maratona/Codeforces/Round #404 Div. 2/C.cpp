#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

int64_t n, m;

bool can(int64_t k){
  return n - k*(k-1)/2 <= m;
}

int64_t solve(){
  int64_t l = 0.0, r = 2e9;
  int64_t mid = 0;
  for(int i = 0; i < 1000; i++){
    mid = (l + r) * 0.5;
    if(can(mid)){
      r = mid;
    }else l = mid;
  }
  return l;
}

int main(){
  cin >> n >> m;
  if(n <= m){
    cout << n << endl;
  }else cout << solve() + m << endl;
  //printf("%Lf\n", solve());
  return 0;
}
