#include <iostream>
#include <cstdio>

#define endl '\n'
#define LL_MAX 0x7FFFFFFFFFFFFFFF 
#define INF ((LL)1e18)
#define LL long long
#define PII pair<int,int>
#define all(V) (V).begin(),(V).end()
using namespace std;
const int MAXN = 3000;

LL dp[MAXN+5][4], cost[MAXN+5], sz[MAXN+5];

int main() {
  //ios_base::sync_with_stdio(0); cin.tie(0);
  int N;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> sz[i];
  }
  for (int i=0; i<N; i++) {
    cin >> cost[i];
    dp[i][1] = cost[i];
  }
	
  for (int i=0; i<N; i++) {
    dp[i][2] = INF;
    for (int j=0; j<i; j++) {
      if (sz[i] > sz[j]) {
        dp[i][2] = min(dp[i][2], dp[j][1] + dp[i][1]);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%lld ", dp[i][2]);
  } puts("");
	
  LL ans = INF;
  //printf("before ans %lld\n", ans);
  for (int i=0; i<N; i++) {
    for (int j=0; j<i; j++) {
      printf("%d %d\n", j, i);
      if (sz[i] > sz[j]) {
        printf("         inside %lld %lld\n", dp[j][2], dp[i][1]);
        ans = min(ans, dp[j][2] + cost[i]);
      }
    }
  }
	
  if (ans == INF) {
    cout << "-1\n";
  }
  else {
    cout << ans << endl;
  }
}
