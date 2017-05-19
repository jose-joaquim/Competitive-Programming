//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1661
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  while((cin >> n) && n){
    long long v[n];
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    long long ans = 0;
    for(int i = 1; i < n; i++){
      ans += abs(v[i-1]);
      v[i] += v[i-1];
    }
    cout << ans << endl;
  }  
  return 0;
}
