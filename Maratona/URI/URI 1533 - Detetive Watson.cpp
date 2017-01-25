//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1533
#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
  while(scanf("%d", &n) && n){
    vector<pair<int, int> > vet;
    for(int i = 0; i < n; i++){
      int u; scanf("%d", &u);
      vet.push_back(make_pair(u, i));
    }
    sort(vet.begin(), vet.end());
    printf("%d\n", vet[n - 2].second + 1);
  }
  return 0;
}
