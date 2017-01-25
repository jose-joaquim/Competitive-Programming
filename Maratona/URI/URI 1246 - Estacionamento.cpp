//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1246
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int C, N;
map<int, pair<int, int> > veiculo;
int est[1005];

void marca(int ini, int fim){
  for(int i = ini; i <= fim; i++){
    est[i] = true;
  }
}

void saiu(int vc){
  ii dem = veiculo[vc];
  for(int i = dem.first; i <= dem.second; i++){
    est[i] = false;
  }
}

bool deu(int placa, int q){
  int cont = 0, ini = 0, fim = -1;
  for(int i = 1; i <= C; i++){
    if(est[i]){ cont = 0; continue; }

    if(cont == 0) ini = i;
    if(++cont == q){
      fim = i;
      break;
    }
  }
  if(fim == -1) return false;
  
  marca(ini, fim);
  veiculo[placa] = ii(ini, fim);
  return true;
}

int main(){
  while(scanf("%d %d", &C, &N) != EOF){
    int ans = 0;
    memset(est, 0, sizeof est);
    veiculo.clear();
    for(int q = 0; q < N; q++){
      cin.ignore();
      char op; scanf("%c", &op);
      if(op == 'C'){
        int placa, q;
        scanf("%d %d", &placa, &q);
        if(deu(placa, q)) ans += 10;
      }
      if(op == 'S'){
        int placa; scanf("%d", &placa);
        saiu(placa);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
