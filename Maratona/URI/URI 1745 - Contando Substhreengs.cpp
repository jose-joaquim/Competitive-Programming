//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1745
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1000010;

int n;
char sub[MAXN];
int dp[MAXN][3];

long long solve(int pos, int sum){
  if(pos == n || isalpha(sub[pos])) return 0;
  
  int &ret = dp[pos][sum];
  if(ret == -1){
    int newNumber = 10*sum + (sub[pos] - '0');
    ret = !(newNumber%3) + solve(pos + 1, newNumber%3);
  }
  
  return ret;
}

int main(){
  scanf("%s", sub);
  n = (int) strlen(sub);
  memset(dp, -1, sizeof dp);
  long long ans = 0;
  for(int i = 0; i < n; i++){
    ans += solve(i, 0);
  }
  printf("%lld\n", ans);
  return 0;
}
