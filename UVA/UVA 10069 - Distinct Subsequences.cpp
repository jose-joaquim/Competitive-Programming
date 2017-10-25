//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1010
//OBS: Actually this code does not work, since the worst case can have a huge answer number, forcing to use Java's Big Integer.
//     But the idea is the same here! :)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string a, b;
int n_a, n_b;
int dp[10004][102];

int solve(int idx, int pref){
  if(pref == n_b){ //end of a solution
    return 1;
  }
  if(idx == n_a + 1){ //solution invalid
    return 0;
  }

  int &ret = dp[idx][pref];

  if(ret == -1){
    ret = 0;
    if(a[idx] == b[pref]){ //can use this char
      ret += solve(idx + 1, pref + 1);
    }

    ret += solve(idx + 1, pref); //not using this char
  }
  
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);  
  int cs; cin >> cs;
  while(cs--){
    cin >> a >> b;
    n_a = (int) a.size();
    n_b = (int) b.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << '\n';
  }
  return 0;
}
