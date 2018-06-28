#include <limits>
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 3001;
const int INF = numeric_limits<int>::max();
//const long long INF = numeric_limits<int>::max() * 1e8 * 4;

int n;
int s[MAXN], c[MAXN];
/*long long dp[MAXN][4][MAXN];

long long solve(int i, int count, int last_s) {
  //printf("%d %d %d\n", i, count, last_s);
  if (count == 3) {
    //puts("           ret1");
    return 0;
  }
  
  if (i == n && count == 3) {
    //puts("           ret2");
    return 0;
  } else if (i == n && count < 3) {
    //puts("           ret3");
    return INF;
  }

  long long &ret = dp[i][count][last_s];

  if (ret == -1) {
    if (last_s != 0 && s[last_s] >= s[i]) {
      //printf("       could not (%d %d %d)\n",  i, count, last_s);
      ret = solve(i + 1, count, last_s);
    } else {
      ll a = solve(i + 1, count, last_s);
      //printf("      not (%d %d %d), %lld\n", i, count, last_s, a);
      ll b = c[i] + solve(i + 1, count + 1, i);
      //printf("      yes (%d %d %d), %lld\n", i, count, last_s, b);
      ret = min(a, b);
      //ret = min(solve(i + 1, count, last_s), c[i] + solve(i + 1, count + 1, s[i]));
    }
  } else {
    //printf("          ___ ja sei %d %d %d\n", i, count, last_s);
  }
  
  return ret;
}*/

int main() {
  //ios::sync_with_stdio(0);
  //memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  //long long ans = solve(0, 0, 0);
  //cout << (ans == INF ? -1 : ans) << '\n';
  int ans = 0;
  int dp[MAXN][4];

  for (int i = 0; i < n; i++) {
     dp[i][0] = c[i];  
  }
  
  for (int i = 0; i < n; i++) {
    dp[i][1] = INF;
    for (int j = 0; j < i; j++) {
      if (s[j] < s[i] && dp[j][0] + c[i] < dp[i][1]) {
        dp[i][1] = dp[i][0] + c[j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    dp[i][2] = INF;
    for (int j = 0; j < i; j++) {
      if (s[j] < s[i] && dp[j][1] + c[i] < dp[i][2]) {
        dp[i][2] = dp[i][1] + c[j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%4d ", dp[i][j]);
    }
    puts("");
  }

  ans = INF;

  for (int i = 0; i < n; i++) {
    ans = min(ans, dp[i][2]);
  }

  cout << (ans == INF ? -1 : ans) << '\n';
  return 0;
}
