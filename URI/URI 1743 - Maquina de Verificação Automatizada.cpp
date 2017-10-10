//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1743

#include <bits/stdc++.h>

using namespace std;

int main(){
  bool ans = true;
  vector<int> vet[2];
  stringstream ss, xx;
  string linha1, linha2;
  getline(cin, linha1);
  ss << linha1;
  string palavra1, palavra2;
  while(ss >> palavra1){
    int num = stoi(palavra1);
    vet[0].push_back(num);
  }
  getline(cin, linha2);
  xx << linha2;
  while(xx >> palavra2){
    int num = stoi(palavra2);
    vet[1].push_back(num);
  }
  for(int i = 0; i < (int) vet[0].size(); i++){
    if(vet[0][i] == vet[1][i]){
      ans = false;
      break;
    }
  }
  puts(ans ? "Y" : "N");
  return 0;
}
