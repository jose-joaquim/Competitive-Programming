#include <stdio.h>

int main() {
  int num,        /* numero dado                                  */
      aux,        /* guarda o pedaco do numero que resta inverter */
      reverso;    /* guarda o numero de tras para frente          */

  printf("Digite um natural: ");
  scanf("%d", &num);

  /* inicializacoes */
  aux = num;
  reverso = 0;

  while (aux != 0) {
    reverso = reverso * 10 + aux % 10;  /* acrescenta mais um digito a direita */
    aux = aux / 10;                     /* joga fora esse digito */
  }

  if (reverso == num)
    printf("%d e' palindrome\n", num);
  else
    printf("%d nao e' palindrome\n", num);

  return 0;
}
