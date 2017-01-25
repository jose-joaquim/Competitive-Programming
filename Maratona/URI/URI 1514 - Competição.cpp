//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1514
#include <bits/stdc++.h>

using namespace std;

int n, m;
int mat[105][105];
int resp[105];
int qtP[105];
int vet[105];

bool c1(){
  for(int i = 0; i < n; i++){
    int qtd = 0;
    for(int j = 0; j < m; j++){
      if(mat[i][j]) qtd++;
      if(qtd == m){
        return false;
      }
    }
  }
  return true;
}

bool c2(){
  for(int i = 0; i < m; i++){
    if(!resp[i]){
      return false;
    }
  }
  return true;
}

bool c3(){
  for(int i = 0; i < m; i++){
    if(qtP[i] == n){
      return false;
    }
  }
  return true;
}

bool c4(){
  for(int i = 0; i < n; i++){
    if(!vet[i]) return false;
  }
  return true;
}

int main(){
  while(scanf("%d %d", &n, &m) && (n || m)){
    int ans = 0;
    memset(qtP, 0, sizeof resp);
    memset(vet, 0, sizeof vet);
    memset(resp, 0, sizeof resp);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        scanf("%d", &mat[i][j]);
        if(mat[i][j]){
          qtP[j]++;
          resp[j] = 1;
          vet[i]++;
        }
      }
    }
    
    if(c1()) ans++;
    if(c2()) ans++;
    if(c3()) ans++;
    if(c4()) ans++;
    
    printf("%d\n", ans);
  }
  return 0;
}
