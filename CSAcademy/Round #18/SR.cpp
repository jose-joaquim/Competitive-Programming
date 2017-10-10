#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b){ return a * (b / gcd(a, b)); }

long long div(long long x){
  //cout << "look " << x << endl;
  vector<long long> v;
  for(long long i = 1; i*i <= x; i++){
    if(x%i == 0){
      //cout << i << endl;
      v.push_back(i);
      if(x/i != i){
        //cout << x/i << endl;
        v.push_back(x/i);
      }
    }
  }
  long long ret = 100000000000;
  for(int i = 0; i < (int) v.size(); i++){
    for(int j = i + 1; j < (int) v.size(); j++){
      if(v[i] * v[j] == x){
        //printf("%d %d\n", v[i], v[j]);
        ret = min(ret, abs(v[i] - v[j]));
      }
    }
  }
  return ret;
}
int main(){
  long long w, h; cin >> w >> h;
  long double sq = sqrt(w * h);
  long long sq_ = sq;
  if(sq_*1.0 == sq){
    cout << 0 << endl;
  }else cout << div(w * h) << endl;
  return 0;
}
