//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1138
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int a, b, n;
vector<int> y;
int dp[10][10][10][10][2];

void splitNumber(int x){
  while(x != 0){
    y.push_back(x % 10);
    x /= 10;
  }
  reverse(y.begin(), y.end());
}

int solve(int i, int qtd, int leftmost_lo, int leftmost_hi, int x, int numero){
  int result = 0;
  if(i == n){
    if(leftmost_lo <= leftmost_hi){
      return qtd;
    }else{
      return 0;
    }
  }

  int &ret = dp[i][qtd][leftmost_lo][leftmost_hi][numero != 0];

  if(ret != -1)
    return ret;

  for(int d = 0; d <= 9; d++){
    int lm_lo = leftmost_lo;
    int lm_hi = leftmost_hi;

    if(d < y[i] && i < lm_lo){
      lm_lo = i;
    }
    if(d > y[i] && i < lm_hi){
      lm_hi = i;
    }

    if(d == 0 and !numero){
      result += solve(i + 1, qtd, lm_lo, lm_hi, x, false);
    }else
      result += solve(i + 1, qtd + (x == d), lm_lo, lm_hi, x, true);
  }

  return ret = result;
}


int main(){
  while(scanf("%d %d", &a, &b) && (a || b)){
    y.clear();
    int ans[10] = {0};
    splitNumber(a - 1);
    n = (int) y.size();
       
    for(int i = 0; i <= 9; i++){
      memset(dp, -1, sizeof dp);
      int ret = solve(0, 0, n, n, i, 0);
      ans[i] = ret;
    }
    y.clear();
    splitNumber(b);
    n = (int) y.size();
    for(int i = 0; i <= 9; i++){
      memset(dp, -1, sizeof dp);
      int qtd = solve(0, 0, n, n, i, 0);
      ans[i] = qtd - ans[i];
      if (i < 9){
	printf("%d ",ans[i]);
      }else{
	printf("%d\n",ans[i]);
      }
    }
  }
  return 0;
}
