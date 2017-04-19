#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;

int n, m;
vector<vi> ad;
vector<int> farAway;

int main(){
  cin >> n >> m;
  ad.assign(n + 1, vi(m + 1));
  farAway.resize(n*m + 1);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      int x; scanf("%d", &x);
      ad[i][j] = x;
    }
  }
  
  for(int col = 1; col <= m; col++){
    for(int row = 1; row <= n; row++){
      int dmy = row;
      while(dmy < n && ad[dmy + 1][col] >= ad[dmy][col]) dmy++;
      farAway[row] = max(dmy, farAway[row]);
      row = dmy;
    }
  }

  for(int i = 1; i <= n; i++){
    farAway[i] = max(farAway[i], farAway[i-1]);
  }

  int k;
  scanf("%d", &k);
  while(k--){
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%s\n", farAway[l] >= r ? "Yes" : "No");
  }
  return 0;
}
