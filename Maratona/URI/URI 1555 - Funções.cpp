//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1555
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int x, y;

int raf(){
  return (9*x*x) + y*y;
}

int beto(){
  return 2*(x*x) + 25*(y*y);
}

int carlos(){
  return -100*x + y*y*y;
}

int main(){
  vector<string> nomes = {"Rafael", "Beto", "Carlos"};
  int T; scanf("%d", &T);
  while(T--){
    scanf("%d %d", &x, &y);
    int ans = -1;
    int r = raf(), b = beto(), c = carlos();
    if(r > b && r > c) ans = 0;
    if(b > r && b > c) ans = 1;
    if(c > r && c > b) ans = 2;
    printf("%s ganhou\n", nomes[ans].c_str());
  }
  return 0;
}
