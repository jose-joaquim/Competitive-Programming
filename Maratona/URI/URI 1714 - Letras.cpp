//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1714
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int dist[105][105], grid[105][105];
int N;

bool can(int i, int j){
  return (i >= 1 && i <= N && j >= 1 && j <= N) && (dist[i][j] == -1);
}

bool maiusculo(int oq){
  return oq >= 65 && oq <= 74;
}

int letter(int oq){
  if(maiusculo(oq)){
    return oq - 65;
  }
  return oq - 97;
}

int bfs(){
  int ret = 100000000;
  bool go = false;
  for(int i = 0; i < (1 << 10); i++){
    memset(dist, -1, sizeof dist);
    dist[1][1] = 0;

    bool cond = maiusculo(grid[1][1]);
    bool cond2 = i & (1 << letter(grid[1][1]));
    
    if(cond != cond2){ continue; }
    
    queue<ii> state; state.push(ii(1, 1));
    
    while(!state.empty()){
      ii pos = state.front(); state.pop();

      if(pos == ii(N, N)){
	go = true;
	ret = min(ret, dist[N][N]);
      }
      
      int dx[] = {-1, 1, 0, 0};
      int dy[] = {0, 0, -1, 1};
      //cima, baixo, esquerda, direita

      for(int k = 0; k < 4; k++){
	int i_new = pos.first + dx[k];
	int j_new = pos.second + dy[k];
	if(can(i_new, j_new)){
	  bool ml = maiusculo(grid[i_new][j_new]);
	  int dic = i & (1 << letter(grid[i_new][j_new]));
	  if((ml && dic != 0) || (!ml && dic == 0)){
	    dist[i_new][j_new] = dist[pos.first][pos.second] + 1;
	    state.push(ii(i_new, j_new));
	  }
	}
      }
    }
  }
  return go ? ret : -1;
}

int main(){
  scanf("%d", &N);
  cin.ignore();
  for(int i = 1; i <= N; i++){
    char line[N+1];
    scanf("%s", line);
    for(int j = 0; j < N; j++){
      grid[i][j+1] = line[j];
    }
  }
  int ans = bfs();
  printf((ans == -1) ? "-1\n" : "%d\n", ans + 1);
  return 0;
}
