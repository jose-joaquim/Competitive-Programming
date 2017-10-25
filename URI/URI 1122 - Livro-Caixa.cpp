//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1122
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int MAXSUM = 16000 * 2 + 4;
const int MAXV = 1600;
const int MAXN = 41;

int dp[MAXN][MAXSUM];
bool pos[MAXN], neg[MAXN];
int val[MAXN];
int n, f;
bool hasSolution;

bool solve(int idx, int sum){
  if(idx == n and sum == f){
    hasSolution = true;
    return true;
  }

  if(idx == n){
    return false;
  }

  int &ret = dp[idx][sum + MAXV];
  bool gopos = false, goneg = false;
  if(ret == -1){    
    gopos = solve(idx + 1, sum + val[idx]);
    goneg = solve(idx + 1, sum - val[idx]);

    if(gopos and !goneg){
      pos[idx] = true;
    }else if(!gopos and goneg){
      neg[idx] = true;
    }else if(gopos and goneg){
      pos[idx] = neg[idx] = true;
    }
    ret = (gopos or goneg);
  }

  return ret;
}

int main(){
  while(scanf("%d %d", &n, &f) and (n || f)){
    hasSolution = false;
    memset(dp, -1, sizeof dp);
    memset(pos, 0, sizeof pos);
    memset(neg, 0, sizeof neg);
    
    for(int i = 0; i < n; i++)
      scanf("%d", val + i);

    solve(0, 0);

    if(!hasSolution){
      puts("*");
    }else{
      for(int i = 0; i < n; i++){
        if(pos[i] and neg[i]) printf("?");
        else if(pos[i]) printf("+");
        else if(neg[i]) printf("-");
      }
      puts("");
    }
  }
  return 0;
}
