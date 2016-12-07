#include <bits/stdc++.h>
using namespace std;

const int K = 45;

int n, k;
int primos[K], qtd_multiplos;

void solve(int pos = 0, int prod = 1, int qtd = 0){
  if(pos == k){
    if(qtd == 0) return;
    
    int multiplos = n/prod;
    
    if(qtd%2 == 0){
      multiplos = -multiplos;
    }
    
    qtd_multiplos += multiplos;
    
    return;
  }
  solve(pos + 1, prod, qtd);
  if(prod * 1LL * primos[pos] <= n){
    solve(pos + 1, prod * primos[pos], qtd + 1);
  }
}

int main(){
  scanf("%d %d", &n, &k);
  for(int i = 0; i < k; i++){
    scanf("%d", &primos[i]);
  }
  solve();
  int ans = n - qtd_multiplos;
  printf("%d\n", ans);
  return 0;
}
