//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2224
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<double, double> dd;

const int MXV = 1 << 16;

double memo[17][1 << 17];
double coord[17][2];
int q;

double dist(double a, double a2, double b, double b2){
  return sqrt(pow(a - b, 2) + pow(a2 - b2, 2));
}

double solve(int i, int mask){
  if(mask == (1 << q) - 1){
    return 0;
  }

  double &ret = memo[i][mask];

  if(ret == -1){
    double ans = 2000000000;
    for(int i = 0; i < q; i++){
      if(!(mask & (1 << i))){
        for(int j = i + 1; j < q; j++){
          if(!(mask & (1 << j))){
            double pl = dist(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
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
  int T; scanf("%d", &T);
  while(T--){
    scanf("%d", &q);

    for(int i = 0; i < q; i++){
      cin >> coord[i][0] >> coord[i][1];
    }
    for(int i = 0 ; i < 17; i++){
      for(int j = 0; j < (1 << 17); j++){
        memo[i][j] = -1.0;
      }
    }
    printf("%.2lf\n", solve(0, 0));
  }
  return 0;
}
