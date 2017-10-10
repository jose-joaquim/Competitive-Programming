//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1136
#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n, b;
vector<int> inside;
int numbers[91];

bool can(){
  memset(numbers, false, sizeof numbers);
  
  for(int i = 0; i < b; i++){
    int x = inside[i];
    for(int j = i; j < b; j++){
      int y = inside[j];
      numbers[(int) fabs(x - y)] = true;
    }
  }

  for(int i = 0; i <= n; i++)
    if(!numbers[i])
      return false; 

  return true;
}

int main(){
  while(scanf("%d %d", &n, &b) && n){
    inside.clear();
    for(int i = 0; i < b; i++){
      int u; scanf("%d", &u);
      inside.push_back(u);
    }

    printf("%s\n", can() ? "Y" : "N");
  }
  return 0;
}
