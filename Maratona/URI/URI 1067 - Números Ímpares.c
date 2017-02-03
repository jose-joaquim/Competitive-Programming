//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1067
#include <stdio.h>

int main(int argc, char **argv)
{
  int x, i; scanf("%d", &x);
  for(i = 1; i <= x; i++){
    if(i%2) printf("%d\n", i);
  }
  return 0;
}

