//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2246
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

#define INF 1000000000

int grid[200][200];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int h, l;

int floodfill(int r, int c, int i, int j){
  if(r < 0 || r >= h || c < 0 || c >= l) return 0;
  if(grid[r][c] != i) return 0;
  int ans = 1;
  grid[r][c] = j;
  for(int d = 0; d < 4; d++){
    ans += floodfill(r + dx[d], c + dy[d], i, j);
  }
  return ans;
}

int main(){
  scanf("%d %d", &h, &l);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < l; j++){
      scanf("%d", &grid[i][j]);
    }
  }
  int minArea = INF;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < l; j++){
      if(grid[i][j] >= 0 && grid[i][j] != INF){
        int k = grid[i][j] == 0 ? INF : (-grid[i][j]);
        minArea = min(minArea, floodfill(i, j, grid[i][j], k));
      }
    }
  }
  printf("%d\n", minArea);
  return 0;
}
