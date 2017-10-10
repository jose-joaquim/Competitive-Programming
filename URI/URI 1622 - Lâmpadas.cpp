//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1622
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void troca(string &aux, int pos){
  if(aux[pos] == 'o'){
    aux[pos] = 'x';
  }else aux[pos] = 'o';
}

int find(string &aux, int k, int n){
  string mx = aux;
  int pos = 0, mod = 0;
  while(true){
    troca(mx, pos);
    mod++;
    pos = (pos + k)%n;
    if(mx == aux) break;
  }
  return mod;
}

int main(){
  ios::sync_with_stdio(false);
  int n, q; 
  while((cin >> n >> q) && n){
    string lamp; cin >> lamp;
    for(int i = 0; i < q; i++){
      int k, m, pos = 0; cin >> k >> m;
      string aux = lamp;
      int mod = find(aux, k, n);
      m %= mod;
      while(m--){
        troca(aux, pos);
        pos = (pos + k)%n;
      }
      cout << aux << '\n';
    }
  }
  return 0;
}
