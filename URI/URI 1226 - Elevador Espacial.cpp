//Author/Autor: Carlos Vinicius @cvfs
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1226

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

char s[30];
long long dp[30][2][2];

long long solve(int pos = 0, bool menor = false, bool um = false){
  if(s[pos] == '\0') return 1;

  long long &ret = dp[pos][menor][um];
  
  if(ret == -1){
    ret = 0;
    for(int i = '0'; i <= '9'; i++){
      if(!menor && i > s[pos]) break;
      if(i == '4' || (um && i == '3')) continue;
      ret += solve(pos + 1, menor || i < s[pos], i == '1');
    }
  }
  return ret;
}

int main(){
  long long n;
  while(scanf("%lld", &n) != EOF){
    unsigned long long l = 1, r = ULLONG_MAX;
    while(l < r){
      unsigned long long mid = l + (r - l)/2;

      sprintf(s, "%llu", mid);

      memset(dp, -1, sizeof(dp));
      long long go = solve() - 1;
      if(go < n) l = mid + 1;
      else r = mid;
    }
    printf("%llu\n", l);
  }
  return 0;
}

