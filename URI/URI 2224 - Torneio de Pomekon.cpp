//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2224
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int N, target;
double memo[1 << 16];
double x[20], y[20];

double dist(double a, double a2, double b, double b2){
  return sqrt(pow(a - b, 2) + pow(a2 - b2, 2));
}

double solve(int mask) {
  
  if (mask == ((1 << N) - 1))
    return memo[mask] = 0;
  
  double &ret = memo[mask];
  if(ret == -1){
    double ans = 2000000000.0;
    int p1, p2;
    
    for (p1 = 0; p1 < N; p1++){
      if (!(mask & (1 << p1))) break;
    }
    
    for (p2 = p1 + 1; p2 < N; p2++){
      if (!(mask & (1 << p2)))
        ans = min(ans, dist(x[p1], y[p1], x[p2], y[p2]) + solve(mask | (1 << p1) | (1 << p2)));
    }
    ret = ans;
  }
  
  return memo[mask];
}

int main() {
  
  int T; scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
      scanf("%lf %lf", &x[i], &y[i]);
    }
    
    for (int i = 0; i < (1 << 16); i++) memo[i] = -1.0;
    printf("%.2lf\n", solve(0));
  }
  return 0;
}

