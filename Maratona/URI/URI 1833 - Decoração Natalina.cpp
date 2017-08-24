//Author/Autor: José Joaquim de Andrade Neto
//With help of Carlos Vinicius - CF cvfs
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1833
#include <set>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

const int INSERTION = 150;
const int DELETION = 30;
const int SUBSTITUTION = 60;

const int MAX_NM = 1001;

int dp[MAX_NM][MAX_NM];
int from[MAX_NM], to[MAX_NM];
int R, M, N;

double editDistDP(){
  
  for(int i = 0; i <= M; i++){
    for(int j = 0; j <= N; j++){
      if(i == 0 && j == 0){
        dp[i][j] = 0;
      }else{
        dp[i][j] = 1000000009;
        if(i > 0 && j > 0){
          dp[i][j] = ((from[i] == to[j])?0:60)+dp[i-1][j-1];
        }
        if(i > 0){
          dp[i][j] = min(dp[i][j],30+dp[i-1][j]);
        }
        if(j > 0){
          dp[i][j] = min(dp[i][j],150+dp[i][j-1]);
        }
      }
    }
  }
  
  return (dp[M][N] / 60.0) * ((double)R);
}

 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int T; cin >> T;
  int cs = 0;
  while(T--){
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    unordered_map<string, int> mapped;
    cout << "Caso #" << ++cs << ": R$ ";
    cin >> R >> M;
    int cnt = 0;
    for(int i = 1; i <= M; i++){
      string u; cin >> u;
      if(mapped.find(u) == mapped.end()){
        mapped[u] = ++cnt;
      }
      from[i] = mapped[u];
    }
    cin >> N;
    for(int i = 1; i <= N; i++){
      string u; cin >> u;
      if(mapped.find(u) == mapped.end()){
        mapped[u] = ++cnt;
      }
      to[i] = mapped[u];
    }
    double param = editDistDP();

    char ans[300];
    sprintf(ans, "%.2lf", param);
    for(int i = 0; ans[i] != '\0'; i++){
      if(ans[i] == '.') ans[i] = ',';
    }
    cout << ans << '\n';
  }
  return 0;
}
