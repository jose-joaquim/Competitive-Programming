//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1987
#include <bits/stdc++.h>

using namespace std;

long long ss(long long x){
  long long ret = 0;
  while(x != 0){
    ret += x%10;
    x /= 10;
  }
  return ret;
}

/*
 * 
 * int ss(int numero){
    if (numero % 10 == numero)
        return numero;
    return ((numero % 10) + ss(numero / 10));
}*/

int main(int argc, char **argv)
{
  long long qtd; 
  while(cin >> qtd){
    long long numero; cin >> numero;
    long long u = ss(numero);
    cout << u;
    if(numero % 3 == 0){
      puts(" sim");
    }else{
      puts(" nao");
    }
  }
  return 0;
}

