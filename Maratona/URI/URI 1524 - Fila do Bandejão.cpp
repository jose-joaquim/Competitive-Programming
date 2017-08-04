#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1001;
const int INF = 1e9 + 7;

int N, K;
int dp[MAXN][MAXN];
int arr[MAXN];

int solve(int n, int k){

  if(n >= N){
    if(!k) return INF;
    else return 0;
  }

  int &ret = dp[n][k];

  if(ret == -1){

    int best = INF;

    best = solve(n + 1, k) + ((n == 0) ? arr[n] : arr[n] - arr[n - 1]);

    if(k){
      best = min(best, solve(n + 1, k - 1));
    }

    ret = best;
  }

  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(cin >> N >> K){
    memset(dp, -1, sizeof dp);
    arr[0] = 0;
    for(int i = 1; i < N; i++){
      cin >> arr[i];
    }
    cout << solve(0, K) << '\n';
  }
  return 0;
}
