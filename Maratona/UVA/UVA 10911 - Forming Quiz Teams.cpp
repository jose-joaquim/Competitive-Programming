//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1852
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
double memo[20][1 << 20];
double crd[20][2];

double dist(double a, double a2, double b, double b2){
  return sqrt(pow(a - b, 2) + pow(a2 - b2, 2));
}

double solve(int i, int mask){
  if(mask == (1 << 2*n) - 1){
    return 0;
  }

  double &ret = memo[i][mask];

  if(ret == -1){
    double ans = 2000000000;
    for(int i = 0; i < 2*n; i++){
      if(!(mask & (1 << i))){
        for(int j = i + 1; j < 2*n; j++){
          if(!(mask & (1 << j))){
            double pl = dist(crd[i][0], crd[i][1], crd[j][0], crd[j][1]);
            ans = min(ans, pl + solve(i + 1, mask | (1 << i) | (1 << j)));
          }
        }
      }
    }
    ret = ans;
  }

  return ret;
}

int main(){
  int cs = 0;
  while(scanf("%d", &n) && n){
    for(int i = 0; i < 2 * n; i++){
      char name[25];
      scanf("%s %lf %lf", name, &crd[i][0], &crd[i][1]);
    }
    for(int i = 0; i < 2*n; i++){
      for(int j = 0; j < (1 << (2*n)); j++){
        memo[i][j] = -1.0;
      }
    }
    printf("Case %d: %.2lf\n", ++cs, solve(0, 0));
  }
  return 0;
}
