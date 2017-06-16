//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1539
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXV = 101;
const int INF = 1000000000;
const double EPS = 1e-9;

int n;
double x[MAXV], y[MAXV], z[MAXV];
double AdjMat[MAXV][MAXV];

double dist(int a, int b){
  return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}

int main(){
  while(scanf("%d", &n) && n){
    for(int i = 1; i <= n; i++){
      scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);
      for(int j = 1; j <= n; j++)
        AdjMat[i][j] = INF;
    }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        //if(i == j) continue;
        double len = dist(i, j);
        //printf("dist entre %d e %d eh %lf\n", i, j, len);
        if(z[i] - len > EPS){
          AdjMat[i][j] = len;
          //printf("liguei %d %d\n", i, j);
        }
        if(z[j] - len > EPS){
          AdjMat[j][i] = len;
          //printf("liguei %d %d\n", j, i);
        }
      }
    }

    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
    
    int q; scanf("%d", &q);
    while(q--){
      int u, v; scanf("%d %d", &u, &v);
      printf("%d\n", (INF - AdjMat[u][v] < EPS) ? -1 : (int)AdjMat[u][v]);
    }    
  }
  return 0;
}
