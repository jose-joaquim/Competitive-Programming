//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1689
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1000000000
#define MAX 1000000 + 15

int T, N, K;
long long memo[1000016];
vector<int> radar, lucro, aux;

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &N, &K);
    memset(memo, 0, sizeof memo);
    radar.assign(MAX, 0); lucro.assign(MAX, 0);
    aux.clear();
    for(int i = 0; i < N; i++){
      int x; scanf("%d", &x);
      aux.push_back(x);
      radar[aux[i]] = true;
    }
    for(int i = 0; i < N; i++){
      int x; scanf("%d", &x);
      lucro[aux[i]] = max(lucro[aux[i]], x);
    }
    for(int i = MAX-2; i >= 0; i--){
      memo[i] = memo[i+1];//pego o lucro do radar da minha frente
      if(radar[i] && i + K < MAX){//se eu tenho um radar nessa posicao E ele nao ultrapassa o ultimo radar
        memo[i] = max(memo[i], lucro[i] + memo[i + K]);
        //entao eu vejo se eh melhor nao pegar OU pegar e somar com o lucro do radar K posicoes a frente
      }
    }
    printf("%d\n", memo[0]);
  }
  return 0;
}
