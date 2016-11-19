//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1750


#include <bits/stdc++.h>

using namespace std;

int n;
int vet[1010];

int dif(int a, int b){
  return min(fabs(a - b), 24 - fabs(a - b));
}

int ans(){
  int resp = dif(vet[n-1], vet[0]);
  for(int i = 2; i < n; i += 2){
    resp += dif(vet[i], vet[i-1]);
  }
  return resp;
}

int ans2(){
  int resp = 0;
  for(int i = 1; i < n; i += 2){
    resp += dif(vet[i], vet[i-1]);
  }
  return resp;
}

int main(){
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i++){
      scanf("%d", &vet[i]);
    }
    sort(vet, vet + n);
    printf("%d\n", min(ans(), ans2()));
  }
  return 0;
}
