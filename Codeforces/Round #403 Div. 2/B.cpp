#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define EPS 1e-6

vector<double> s, t;
int n;

double times(double pos){
  double ret = 0.0;
  for(int i = 0; i < n; i++){
    ret = max(ret, fabs(pos - s[i])/t[i]);
  }
  return ret;
}

double times2(double sec){
  double o = 1e9, we = -1e9;
  for(int i = 0; i < n; i++){
    we = max(we, s[i] - t[i] * sec);
    o = min(o, s[i] + t[i] * sec);
  }
  return we <= o;
}

double solve(){
  double l = 0.0, h = 1e9;
  double ans;
  for(int i = 0; i < 1000; i++){
    double mid = l + (h - l)/3;
    double mid2 = h - (h - l)/3;
    double look = times(mid), look2 = times(mid2);
    if(look < look2){
      ans = mid;
      h = mid2;
    }else{
      l = mid;
    }
  }
  return times(ans);
}

double solve2(){
  double l = 0.0, h = 1e9;
  double ans, mid;
  for(int i = 0; i < 1000; i++){
    mid = (l + h)/2;
    if(times2(mid)){
      ans = mid;
      h = mid;
    }else{
      l = mid;
    }
  }
  return mid;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int u; cin >> u;
    s.push_back(u);
  }
  for(int i = 0; i < n; i++){
    int u; cin >> u;
    t.push_back(u);
  }
  printf("%lf\n", solve2());
  return 0;
}
