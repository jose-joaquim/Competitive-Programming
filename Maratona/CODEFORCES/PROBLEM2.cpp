#include <bits/stdc++.h>

using namespace std;

int n;
int vet[200005];
int memo[200005][2];

bool solve(int i, bool resto){
  if (i  < n && !vet[i] && resto) return 0;
  if (i == n && !resto) return 1;

  bool par = (vet[i] % 2) == 0;
  bool imp = (vet[i] % 2) == 1;
  
  if (memo[i][resto] != -1) return memo[i][resto];
  
  if (par && !resto){
    return memo[i][resto] = solve(i + 1, false);
  }else if(par && resto){
    return memo[i][resto] = solve(i + 1, true);
  }else if(imp && resto){
    return memo[i][resto] = solve(i + 1, false);
  }else if(imp && !resto){
    return memo[i][resto] = solve(i + 1, true);
  }
  
}

int main(){
  while(scanf("%d", &n) != EOF){
    for(int i = 0; i < n; i++){
      scanf("%d", &vet[i]);
    }
    memset(memo, -1, sizeof memo);
    puts((solve(0,false) > 0) ? "YES" : "NO");
  }
  return 0;
}
