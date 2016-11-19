//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2014


#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int N, Q;
int s, t;
vi p;
vector<vi> AdjList;
vi match, vis;   

int Aug(int l) {               
  if (vis[l]) return 0;                              
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;                         
  } }
  return 0;                                                
}


int main(){
  while(scanf("%d %d", &N, &Q) != EOF){
    bool paiPerfeito = false;
    int Pais[105][105];
    memset(Pais, 0, sizeof Pais);
    int V = 0, Vleft = 0;
    for(int i = 0; i < N; i++){
      int qtd; cin >> qtd;
      if(qtd == N) paiPerfeito = true;
      V += qtd;
      for(int j = 0; j < qtd; j++){
		int alelo; cin >> alelo;
		Pais[i][alelo] = 1;
      }
    }
    for(int cs = 0; cs < Q; cs++){
      AdjList.assign(N*N, vi());
      vector<int> filho;
      int B; cin >> B;
      if(paiPerfeito && !B){
		puts("N");
		continue;
      }
      V += B;
      for(int j = 0; j < B; j++){
		int alelo; cin >> alelo;
		filho.push_back(alelo);
      }
      for(int i = 0; i < B; i++){
		for(int pai = 0; pai < N; pai++){
		  if(Pais[pai][filho[i]]){
			AdjList[i].push_back(pai);
		  }
		}
      }
      Vleft = B; 
      int MCBM = 0;
      match.assign(V, -1);   
      for (int l = 0; l < Vleft; l++) {     
		vis.assign(Vleft, 0);                 
		MCBM += Aug(l);
      }
      puts(MCBM == B ? "Y" : "N");
    }
  }
  return 0;
}
