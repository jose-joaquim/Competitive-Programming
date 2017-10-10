#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<double, double> dd;

int nx[6 * 100000], ny[6 * 100000], x, es;

double dist(double a, double b, double x, double y){
  return sqrt(pow(x - a, 2) + pow(y - b, 2));
}

double f(double pos){
  double ret = -1e9;
  for(int i = 0; i < es; i++){
    ret = max(ret, dist(pos, 0, nx[i], ny[i]));
  }
  return ret;
}

dd ternary(){
  double l = 0.0, r = 1.0*x, mid;
  double ans;
  for(int t = 0; t < 80; t++){
    double left = l + (r - l)/3;
    double right = r - (r - l)/3;
    if(f(left) > f(right)){
      l = left;
    }else{
      r = right;
    }
  }
  return dd(l, f(l));
}

int main(){
  scanf("%d %d", &es, &x);
  for(int i = 0; i < es; i++){
    scanf("%d %d", &nx[i], &ny[i]);
  }
  dd tef = ternary();
  printf("%.2lf %.2lf\n", tef.first, tef.second);
  return 0;
}
