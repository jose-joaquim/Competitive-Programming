//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2384
#include <bits/stdc++.h>

using namespace std;

int n, d, r;
int mon[105], eve[105];

int main(){
  while(scanf("%d %d %d", &n, &d, &r) && (n || d || r)){
    for(int i = 0; i < n; i++) scanf("%d", &mon[i]);
    for(int i = 0; i < n; i++) scanf("%d", &eve[i]);
    sort(mon, mon + n); sort(eve, eve + n, greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++){
      int l = mon[i] + eve[i];
      if(l > d){
        ans += (l - d)*r;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
