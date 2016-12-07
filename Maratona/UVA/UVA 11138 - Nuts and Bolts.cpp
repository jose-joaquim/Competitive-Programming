//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2079
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int T, l, r;
vector<vi> AdjList;
vi match, vis;                                      

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

int main(){
  scanf("%d", &T);
  for(int cs = 1; cs <= T; cs++){
    scanf("%d %d", &l, &r);
    AdjList.assign(l + r + 1, vi());
    for(int i = 0; i < l; i++){
      for(int j = 0; j < r; j++){
		int w; scanf("%d", &w);
		if(w){
		  AdjList[i].push_back(j);
		}
      }
    }
    int MCBM = 0;
    int Vleft = l; int V = l + r;
    match.assign(V, -1);   
    for (int l = 0; l < Vleft; l++) {    
      vis.assign(Vleft, 0);              
      MCBM += Aug(l);
    }
    
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", cs, MCBM);
  }
  return 0;
}
