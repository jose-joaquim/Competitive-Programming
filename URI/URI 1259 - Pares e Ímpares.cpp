//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1259
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n; scanf("%d", &n);
  vector<int> p, i;
  for(int q = 0; q < n; q++){
    int v; scanf("%d", &v);
    if(v % 2){
      i.push_back(v);
    }else p.push_back(v);
  }
  sort(p.begin(), p.end());
  sort(i.rbegin(), i.rend());
  for(int q = 0; q < (int) p.size(); q++){
    printf("%d\n", p[q]);
  }
  for(int q = 0; q < (int) i.size(); q++){
    printf("%d\n", i[q]);
  }
  return 0;
}
