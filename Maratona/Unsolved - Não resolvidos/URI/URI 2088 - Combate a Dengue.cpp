#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;

#define INF 1000000000

double memo[20][1 << 15];
double grid[20][20];
int iniX, iniY, citys;

double dist(int a1, int b1, int a2, int b2){
  return sqrt(pow(a2 - a1, 2) + pow(b2 - b1, 2));
}

double tsp(int pos, int mask){
  if((1 << citys) - 1 == mask){
    return grid[pos][0];
  }
  if(memo[pos][mask] != -1) return memo[pos][mask];
  double ans = INF;
  for(int nxt = 0; nxt < citys; nxt++){
    if(nxt != pos && !(mask & (1 << nxt))){
      ans = min(ans, grid[pos][nxt] + tsp(nxt, mask | (1 << nxt)));
    }
  }
  return memo[pos][mask] = ans;
}

int main(){
  int n;
  while(scanf("%d", &n) && n){
    memset(memo, -1, sizeof memo);
    scanf("%d %d", &iniX, &iniY);
    int vet[n+2][n+2];
    citys = n + 1;
    vet[0][0] = iniX; vet[0][1] = iniY;
    for(int i = 1; i <= n; i++){
      scanf("%d %d", &vet[i][0], &vet[i][1]);
    }
    for(int i = 0; i <= n; i++){
      for(int j = 0; j <= n; j++){
	double value = dist(vet[i][0], vet[i][1], vet[j][0], vet[j][1]);
	grid[i][j] = value;
      }
    }

    printf("%2.lf\n", tsp(0, 1));
  }
  return 0;
}
