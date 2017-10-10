//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1203
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef vector<int> vi;

#define INF 1000000000

int R, K;
int dp[150][150];
int grau[150];
bool ans;

int solve(int id, int W){
  if(W == K) ans = ans | true;
  if(W > K) ans = ans | false;
  if(id == R || W > K){
    ans = ans | false;
    return -INF;
  }
  int &ret = dp[id][W];
  if(grau[id] + W > K) return ret = solve(id + 1, W);
  if(ret == -1){
    ret = max(solve(id + 1, W), grau[id] + solve(id + 1, W + grau[id]));
  }
  return ret;
}

int main(){
  while(scanf("%d %d", &R, &K) != EOF){
    ans = false;
    memset(dp, -1, sizeof dp);
    memset(grau, 0, sizeof grau);
    for(int i = 0; i < K; i++){
      int u, v; scanf("%d %d", &u, &v);
      grau[u-1]++, grau[v-1]++;
    }
    solve(0, 0);
    puts(ans ? "S" : "N");
  }
  return 0;
}
