//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1024
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

bool isLetter(char oq){
  return (oq >= 97 & oq <= 122) || (oq >= 65 && oq <= 90);
}
int main(){
  int T; scanf("%d", &T);
  bool go = true;
  while(T--){
    if(go){ cin.ignore(); go = false; }
    string texto, reverse; getline(cin, texto);
    //cout << "li " << texto << endl;
    int sz = (int) texto.size();
    for(int i = 0; i < sz; i++){
      if(isLetter(texto[i])){
        texto[i] = texto[i] + 3;
      }
    }

    for(int i = sz - 1; i >= 0; i--){
      reverse += texto[i];
    }
    
    for(int i = sz/2; i < sz; i++){
      reverse[i] -= 1;
    }
    cout << reverse << endl;
  }
  return 0;
}
