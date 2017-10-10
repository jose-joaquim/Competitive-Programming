#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int n, k; cin >> n >> k;
  int ans = 0;
  while(n != 0){
    ans += (n/k)*k;
    int more = (n/k) + (n%k);
    n = more;
    if(n < k){
      ans += n;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
