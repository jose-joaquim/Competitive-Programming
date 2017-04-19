#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  int A[n], B[m];
  for(auto &x : A){
    cin >> x;
  }
  for(auto &x : B){
    cin >> x;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(abs(A[i] - B[j]) >= k) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
