//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1021
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vi match, vis;         
int n, m, s, v;
double bicho[105][2], hole[105][2];

double dist(double x1, double x2, double y1, double y2){
  double ret = sqrt(pow(y1 - x1, 2) + pow(y2 - x2, 2));
  return ret;
}

int Aug(int l) {
  if (vis[l]) return 0;                            
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;                      
  } }
  return 0; 
}

bool cant(double dd){
  return dd/(1.0*v) < (1.0*s); 
}

int main(){
  while(scanf("%d %d %d %d", &n, &m, &s, &v) != EOF){
    AdjList.assign(n + m + 3, vi());
          
    for(int i = 0; i < n; i++){
      scanf("%lf %lf", &bicho[i][0], &bicho[i][1]);
    }
    for(int i = 0; i < m; i++){
      scanf("%lf %lf", &hole[i][0], &hole[i][1]);
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(cant(dist(bicho[i][0], bicho[i][1], hole[j][0], hole[j][1]))){
          AdjList[i].push_back(j);
        }
      }
    }
    
    int MCBM = 0; int V = n + m;
    int Vleft = n;
    match.assign(V, -1); 
    for (int l = 0; l < Vleft; l++) {  
      vis.assign(Vleft, 0);
      MCBM += Aug(l);
    }
    printf("%d\n", n - MCBM);
  }
  return 0;
}
