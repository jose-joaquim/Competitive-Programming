#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  int n; cin >> n;
  int s[2*n + 1];
  for(int i = 0; i < 2*n; i++){
    scanf("%d", &s[i]);
  }
  map<int, bool> table; int ans = -1, k = 0;
  for(int i = 0; i < 2*n; i++){
    if(table.find(s[i]) == table.end()){
      table[s[i]] = true;
      ans = max(ans, ++k);
    }else{
      table.erase(s[i]);
      k--;
    }
  }
  printf("%d\n", ans);
  return 0;
}
