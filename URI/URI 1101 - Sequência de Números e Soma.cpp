//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1101

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  while(scanf("%d %d", &n, &m) && (n > 0 && m > 0)){
    if(n > m) swap(n, m);
    int sum = 0;
    for(int i = n; i <= m; i++){
      printf("%d ", i);
      sum += i;
    }
    printf("Sum=%d\n", sum);
  }  
  return 0;
}
