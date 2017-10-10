//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3562
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

const int INF = 1000000000;

int main(){
  ios::sync_with_stdio(false);
  int n, s;
  while(cin >> n >> s){
    vector<int> vet(n);
    for(auto &x : vet) cin >> x;
    int ans = INF, sum = vet[0];
    int left = 0, right = 0;
    for(int i = 1; i < n; i++){
      sum += vet[i];
      right = i;
      while(left < right){
        if(sum - vet[left] >= s){
          sum -= vet[left];
          left++;
        }else break;
      }
      if(sum >= s) ans = min(ans, right - left + 1);
    }
    cout << (ans != INF ? ans : 0) << endl;
  }
  return 0;
}
