//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1080

#include <iostream>
#include <string.h>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int n, m;
bool ans;

int main(){
  while(scanf("%d %d", &n, &m) != EOF){
    ans = true;
    int op1 = m, op2 = n;
    //vou guardar os expoentes
    map<int, int> factorsM, factorsN;
    vector<int> vet_M, vet_N;
    for(int i = 2; i*i <= m; i++){
      int cont = 0;
      while(m % i == 0){
		m /= i;
		cont++;
      }
      if(cont > 0){
		factorsM[i] = cont;
		vet_M.push_back(i);
      }
    }
    if(m > 1){
      factorsM[m] = 1;
      vet_M.push_back(m);
    }
    for(int i = n; i >= 2; i--){
      int aux = i;
      for(int j = 2; j*j <= i; j++){
        int cont = 0;
		while(aux % j == 0){
		  aux /= j;
		  cont++;
		}
		if(cont > 0){
		  factorsN[j] += cont;
		  vet_N.push_back(j);
		}
      }
    }
    if(n > 1){
      factorsN[n] = 1;
      vet_N.push_back(m);
    }
    printf("expoentes de %d sao: \n", op2);
    for(int i = 0; i < (int) vet_N.size(); i++){
      printf("%d com quantidade %d\n", vet_N[i], factorsN[vet_N[i]]);
    }
    puts("");
    for(int i = 0; i < (int) vet_M.size(); i++){
      if(factorsN[vet_M[i]] < factorsM[vet_M[i]]){
		ans = false;
		break;
      }
    }
    if(ans) printf("%d divides %d!\n", op1, op2);
    else printf("%d does not divide %d!\n", op1, op2);
  }
  return 0;
}
