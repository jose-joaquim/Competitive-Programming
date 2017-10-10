//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1709
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int pot[20];

int main(){
  int p;
  while(scanf("%d", &p) != EOF){
    int n = p/2;
    vector<int> A(p);
    for(int i = 0; i < p; i++){
      A[i] = i + 1;
    }
    int pos = 0, k = 0, newPos = 0; int ct = 0;
    do{
      if(pos < n){
        pos = 1 + 2*pos;
      }else{
        pos = pos - (p - pos);
      }
    }while(++k && pos != 0);
    printf("%d\n", k);
  }
  return 0;
}
