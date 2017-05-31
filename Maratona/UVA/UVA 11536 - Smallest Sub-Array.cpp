//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=16&problem=2531&mosmsg=Submission+received+with+ID+19448632
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int INF = 1000000000;

bool allCovered(vector<int> &r, int k){
  for(int i = 1; i <= k; i++){
    if(r[i] == 0){ return false; }
  }
  return true;
}

int main(){
  int T; scanf("%d", &T);
  int cs = 0;
  while(T--){
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    vector<int> arr(n + 2), f(k + 1, 0);
    arr[0] = 1, arr[1] = 2, arr[2] = 3;
    int sum = 6, l = 0, cnt = 0;
    for(int i = 3; i < n; i++){
      arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3])%m + 1;
    }
    int lim = 0, i = 0;
    int right = 0, left = 0, ans = INF;
    while(right < n){
      if(arr[right] <= k){
        f[arr[right]]++;
      }
      while(allCovered(f, k)){
        ans = min(ans, right - left + 1);
        if(arr[left] <= k) f[arr[left]]--;
        left++;
      }
      right++;
    }
    printf("Case %d: ", ++cs);
    if(ans == INF) puts("sequence nai");
    else printf("%d\n", ans);
  }
  return 0;
}
