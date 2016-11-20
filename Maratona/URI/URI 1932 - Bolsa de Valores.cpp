//Author/Autor: José Joaquim de Andrade Neto
//Agradecimento a Carlos Vinícios que me fez olhar a minha ideia de outra forma
//Thanks to Carlos Vinícios who helped me to see my ideia with another eyes
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1932

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long memo[200005][2];
int vet[200005];
int N, C;

long long solve(int dia, int take){
  long long &ans = memo[dia][take];
  
  if(dia >= N){
	return 0;
  }
  
  if(ans == -1){
	//o melhor entre não fazer nada e (vender OU comprar)
    ans = max(solve(dia + 1, take), take ? solve(dia + 1, 0) + vet[dia] : solve(dia + 1, 1) - C - vet[dia]);
  }
  
  return ans;
}

int main(){
  while(scanf("%d %d", &N, &C) != EOF){
	memset(memo, -1, sizeof memo);
	for(int i = 0; i < N; i++){
	  scanf("%d", &vet[i]);
	}
    printf("%lld\n", solve(0, 0));
  }
  return 0;
}
