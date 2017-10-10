//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=728
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll num;
  while(scanf("%lld", &num) != EOF){
    vector<ll> A; A.push_back(num);
    while(scanf("%lld", &num) && num != -999999) A.push_back(num);
    ll prod = 1, ans = 1, max_end = 1, min_end = 1;
    for(int i = 0; i < (int) A.size(); i++){
      if(A[i] == 0){
        max_end = min_end = 1;
      }else if(A[i] > 0){
        max_end = max_end*A[i];
        min_end = min(min_end*A[i], (ll) 1);
      }else{
        long long temp = max_end;
        max_end = max(min_end * A[i], (ll) 1);
        min_end = temp*A[i];
      }
      ans = max(ans, max_end);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
