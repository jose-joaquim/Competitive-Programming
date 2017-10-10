#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
 
using namespace std;
 
typedef pair<double, double> dd;
 
double memo[20][1 << 20];
double coord[20][2];
double grid[20][20];
 
int n, citys;
 
double dist(double a, double a2, double b, double b2){
  return sqrt(pow(a - b, 2) + pow(a2 - b2, 2));
}
 
double solve(int i, int mask){
  if((1 << citys) - 1 == mask){
    return grid[i][0];
  }
 
  double &ret = memo[i][mask];
  if(ret == -1.0){
    double ans = 2000000000;
    for(int j = 0; j < citys; j++){
      if(j != i && !(mask & (1 << j))){
        ans = min(ans, grid[i][j] + solve(j, mask | (1 << j)));
      }
    }
    ret = ans;
  }
 
  return ret;
}
 
int main(){
  while(scanf("%d", &n) && n){
    citys = n + 1;
    scanf("%lf %lf", &coord[0][0], &coord[0][1]);
    for(int i = 1; i <= n; i++){
      scanf("%lf %lf", &coord[i][0], &coord[i][1]);
    }
    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= n; j++){
        if(i == j) grid[i][j] = 0;
        else{
          grid[i][j] = dist(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
        }
      }
    }
    for(int i = 0; i <= citys; i++){
      for(int j = 0; j <= (1 << citys); j++){
        memo[i][j] = -1.0;
      }
    }
    printf("%.2lf\n", solve(0, 1));
  }  
  return 0;
}
