#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int t, n, k, ans;
vector<int> pos, value;

void solve(){
  ans = value[0];
  for(int i = 1; i < n; i++){
    
  }
}

void solve2(int anterior, bool pego){
  
}

int main(){
  scanf("%d", &t);
  for(int q = 0; q < t; q++){
    ans = 0;
    pos.clear(); value.clear();
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
      int x; cin >> x;
      pos.push_back(x);
    }
    for(int i = 0; i < n; i++){
      int x; cin >> x;
      value.push_back(x);
    }
    solve();
    printf("%d\n", ans);
  }
  return 0;
}
