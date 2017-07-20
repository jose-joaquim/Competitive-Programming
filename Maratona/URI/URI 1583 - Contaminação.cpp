//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1583
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char grid[51][51]; int visited[51][51];
int n, m;

void floodfill(int r, int c){
  if(r >= n || r < 0 || c >= m || c < 0) return ;
  if(grid[r][c] == 'X' || visited[r][c]) return ;
  //printf("%d %d %c\n", r, c, grid[r][c]);
  grid[r][c] = 'T';
  visited[r][c] = true;
  for(int k = 0; k < 4; k++){
    floodfill(r + dx[k], c + dy[k]);
  }
}

int main(){
  while(scanf("%d %d", &n, &m) && n){
    cin.ignore();
    memset(visited, false, sizeof visited);
    for(int i = 0; i < n; i++){
      string line;
      getline(cin, line);
      for(int j = 0; j < m; j++){
        grid[i][j] = line[j];
      }
    }

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(grid[i][j] == 'T') floodfill(i, j);

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        printf("%c", grid[i][j]);
      }
      puts("");
    }     

    puts("");
  }
  return 0;
}
