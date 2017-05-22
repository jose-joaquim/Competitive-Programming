#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MXV = 100001;
const int MXM = 1001;

int v, m;
int dp[MXV][MXM];
int coins[MXM];


//item, soma
bool solve(int j, int sum){

  //se a soma chegou a 0
  for(int i = 0; i <= m; i++){
    dp[0][i] = true;
  }

  //se a soma != 0 e acabaram os itens
  for(int i = 1; i <= v; i++){
    dp[i][0] = false;
  }

  for(int i = 1; i <= sum; i++){
    for(int j = 1; j <= m; j++){
      dp[i][j] = dp[i][j-1];
      if(i >= coins[j-1]){
        dp[i][j] = dp[i][j] || dp[i - coins[j-1]][j-1];
      }
    }
  }
  

  return dp[sum][j];
}

int main(){
  ios::sync_with_stdio(false);
  cin >> v >> m;
  for(int i = 0; i < m; i++) cin >> coins[i];
  cout << (solve(m, v) ? "S" : "N") << '\n';
  return 0;
}

/*#include <bitset>
#include <cstdio>
 
using namespace std;
 
int main() {
  bitset<100001> b;
  b[0] = true;
 
  int v, m;
  scanf("%d %d", &v, &m);

  bool done = false;
  while (m--){
    int moeda;
    scanf("%d", &moeda);
    b |= b << moeda;

    if (b[v]) {
      printf("S\n");
      done = true;
      break;
    }
  }

  if (!done)
    printf("N\n");
}*/
