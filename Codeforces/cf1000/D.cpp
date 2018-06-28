#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1001;
const int MOD = 998244353;

int n;
int arr[MAXN];
int dp[MAXN][MAXN];

int solve(int i = 0, int sum = 0) {
  if (i == n) {
    return sum == 0;
  }

  int &ret = dp[i][sum];

  if (ret == -1) {
    ret = solve(i + 1, sum);
    
    if (sum == 0) {
      if (arr[i] >= 1 && arr[i] < n) {
        ret = (ret + solve(i + 1, arr[i])%MOD)%MOD;
      }
    } else {
      ret = (ret + solve(i + 1, sum - 1)%MOD)%MOD;
    }
  }
  
  return ret;
}

int main() {
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  memset(dp, -1, sizeof dp);
  cout << (solve() - 1)%MOD << '\n';
  
  return 0;
}
