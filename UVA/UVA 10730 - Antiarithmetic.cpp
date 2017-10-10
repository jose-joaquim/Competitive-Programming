//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1671

#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>

using namespace std;

int vet[10000];
int estado[10001];
int raz = -1, n;

/*bool backtrack(int c, int razao){
	if(c == 3) return true;
	estado[c] = vet[c]-vet[c-1];
	if(estado[c-1] == razao) return false;
	for(int i = 1; i < n; i++){
		backtrack(c+i, vet[i] - vet[i-1]);
	} 
	return true;
}*/

bool isArithmetic(){

	for(int i = 0; i+1 < n; i++){
			
		for(int j = i+1; j < n; j++){
			int razao = fabs(vet[j] - vet[i]);
			for(int k = j + 1; k < n; k++){
				if((vet[k] - vet[j]) == razao){
					return false;
				}
			}
		}
	}
	return true;
}

int main(int argc, char **argv)
{
	while(scanf("%d: ", &n) && n != 0){
		memset(vet, 0, n);
		//memset(estado, 0, sizeof estado);
		for(int i = 0; i < n; i++){
			scanf("%d", &vet[i]);
		}
		bool resp = isArithmetic();
		puts (resp ? "yes":"no");
	}
	return 0;
}
/*
 * #include <stdio.h>
 
int main() {
  int n;
  while (scanf("%d:", &n) && n) {
    int i, j, pos[10000];
    for (i = 1; i <= n; i++) {
      scanf("%d", &j);
      pos[j] = i;
    }
    int gg = 0;
    for (i = 0; i < n && !gg; i++) {
      for (j = 1; i + 2 * j < n && !gg; j++) {
        gg = (pos[i] < pos[i + j] && pos[i + j] < pos[i + 2 * j]);
      }
    }
    puts(gg ? "no" : "yes");
  }
  return 0;
}*/

