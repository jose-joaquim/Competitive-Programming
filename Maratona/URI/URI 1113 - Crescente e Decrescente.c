//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1113
#include <stdio.h>

int main(int argc, char **argv)
{
  int x, i; 
  while(scanf("%d %d", &x, &i) && x != i){
    puts(x > i ? "Decrescente" : "Crescente");
  }
  return 0;
}

