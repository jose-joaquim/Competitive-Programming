#include <cstdio>
#include <iostream>

using namespace std;

const int N = 510;

bool black[N][N], white[N][N];
int db[N][N], dw[N][N];

int main(){
  int n, p;
  scanf("%d %d", &n, &p);
  for(int i = 0; i < p; i++){
    int l, c;
    scanf("%d %d", &l, &c);
    black[l][c] = 1;
  }
  for(int i = 0; i < p; i++){
    int l, c;
    scanf("%d %d", &l, &c);
    white[l][c] = 1;
  }
  long long ansb = 0, answ = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(black[i][j]){
        db[i][j] = 0;
      }else{
        db[i][j] = min(db[i - 1][j - 1], min(db[i - 1][j], db[i][j - 1])) + 1;
      }
      if(white[i][j]){
        dw[i][j] = 0;
      }else{
        dw[i][j] = min(dw[i - 1][j - 1], min(dw[i - 1][j], dw[i][j - 1])) + 1;
      }
      ansb += max(0, dw[i][j] - db[i][j]);
      answ += max(0, db[i][j] - dw[i][j]);
    }
  }
  printf("%lld %lld\n", ansb, answ);
  return 0;
}
