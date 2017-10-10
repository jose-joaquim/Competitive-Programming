//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2267
#include <bits/stdc++.h>

using namespace std;

int dragons[200005], knights[200005];
int n, m;

int main(){
  while(scanf("%d %d", &n, &m) && (n || m)){
    int ans = 0;
    for(int i = 0; i < n; i++) scanf("%d", &dragons[i]);
    for(int i = 0; i < m; i++) scanf("%d", &knights[i]);
    sort(dragons, dragons + n);
    sort(knights, knights + m);
    int d = 0, k = 0;
    while(d < n && k < m){
      while(dragons[d] > knights[k] && k < m) k++;
      if(k == m) break;
      ans += knights[k];
      d++; k++;
    }
    printf(d == n ? "%d\n" : "Loowater is doomed!\n", ans);
  }
  return 0;
}
