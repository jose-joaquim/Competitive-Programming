//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1490
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
char grid[105][105];
int columns[105], lines[105];

map<pair<int, int>, vii> AdjList2;
map<ii, bool> exists;
map<ii, ii> match;
map<ii, int> vis;
vector<ii> v_Vleft;
int n_vertices;

int Aug(ii l) {                 
  if (vis.find(l) != vis.end()) return 0;                  
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList2[l].size(); j++) {
    ii r = AdjList2[l][j];
    if (match.find(r) == match.end() || Aug(match[r])) {
      match[r] = l; return 1;            
    } }
  return 0;                                                 
}

void make_graph(){
  n_vertices = 0;
  exists.clear();
  v_Vleft.clear();
  memset(lines, 0, sizeof lines);
  memset(columns, 0, sizeof columns);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(grid[i][j] == 'X'){
        columns[j]++;
        lines[i]++;
      }else{
        AdjList2[ii(i+1, lines[i]+1)].push_back(ii(n*n + j+1, columns[j]+1));
        if(exists.find(ii(i+1, lines[i]+1)) == exists.end()){
          exists[ii(i+1, lines[i]+1)] = true;
          n_vertices++;
          v_Vleft.push_back(ii(i + 1, lines[i] + 1));
        }
        if(exists.find(ii(n * n + j+1, columns[j]+1)) == exists.end()){
          exists[ii(n * n + j+1, columns[j]+1)] = true;
          n_vertices++;
        }
      }
    }
  }
}

void init(){
  match.clear();
  v_Vleft.clear();
  vis.clear();
  exists.clear();
  n_vertices = 0;
  AdjList2.clear();
}

int main(){
  while(scanf("%d", &n) != EOF){
    init();
    cin.ignore();
    for(int i = 0; i < n; i++){
      string linha; getline(cin, linha);
      for(int j = 0; j <(int) linha.size(); j++){
        grid[i][j] = linha[j];
      }
    }
    make_graph();
    int MCBM = 0;
    int Vleft = (int) v_Vleft.size();
    match.clear();
    for (int l = 0; l < Vleft; l++) { 
      vis.clear();        
      MCBM += Aug(v_Vleft[l]);
    }
    printf("%d\n", MCBM);
  }
  return 0;
}
