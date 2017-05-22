#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

const int INF = 2000000000;

int n;
int x[20];
int dp[1 << 16];

int solve(int mask){

  if(mask == (1 << n) - 1){
    return 0;
  }

  int &ret = dp[mask];

  if(ret == -1){
    int ans = 0;
    int p1, p2, p3;
    for(p1 = 0; p1 < n; p1++){
      if(!(mask & (1 << p1))) break;
    }

    for(p2 = p1 + 1; p2 < n; p2++){
      if(!(mask & (1 << p2))){
        for(p3 = p2 + 1; p3 < n; p3++){
          bool go = (x[p1] + x[p2] + x[p3] >= 20) ? 1 : 0;
          if(!(mask & (1 << p3)) && go){
            ans = max(ans, 1 + solve(mask | (1 << p1) | (1 << p2) | (1 << p3)));
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
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) scanf("%d", &x[i]);
    int ans = solve(0);
    printf("Case %d: %d\n", ++cs, (ans != 2000000000) ? ans : 0);
  }
  return 0;
}
