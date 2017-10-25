//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3679
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 32;
const int MAXV = 3100;

char exp[MAXN * 2];
int dp[MAXN][MAXN][MAXV * 2];
int used[MAXV * 2];
vector<int> sign, num;

int n;

void solve(int i, int abertos, int valor){
  if(dp[i][abertos][valor + MAXV])
    return;

  dp[i][abertos][valor + MAXV] = true;
  
  if(i == n){
    used[valor + MAXV] = true;
    return;
  }  

  int nval = valor + num[i] * sign[i] * ((abertos % 2 == 0) ? 1 : -1);

  if(sign[i] == -1)
    solve(i + 1, abertos + 1, nval);

  if(abertos > 0)
    solve(i + 1, abertos - 1, nval);

  solve(i + 1, abertos, nval);
}

int main(){
  string line;
  while(getline(cin, line)){
    sign.clear(); num.clear();
    memset(used, 0, sizeof used);
    memset(dp, 0, sizeof dp);
    stringstream ss(line);
    string aux;
    sign.push_back(1);
    while(ss >> aux){
      if(aux[0] == '-'){
        sign.push_back(-1);
      }else if(aux[0] == '+'){
        sign.push_back(1);
      }else{
        num.push_back(stoi(aux));
      }
    }
    n = (int) sign.size();
    solve(0, 0, 0);

    int ans = 0;
    for(int i = 1; i < MAXV * 2; i++){
      if(used[i])
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
