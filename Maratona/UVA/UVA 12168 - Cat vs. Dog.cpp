//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3320

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList;
vector<pair<int, int> > cat, dog;
vi match, vis;
int c, d, v, n;

int Aug(int l) {             
  if (vis[l]) return 0;      
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])){
      match[r] = l; return 1;
  } }
  return 0;
}

int main(){
  scanf("%d", &n);
  while(n--){
    scanf("%d %d %d", &c, &d, &v);
    dog.clear(); cat.clear();
    int Vleft = c;
    for(int i = 0; i < v; i++){
      cin.ignore();
      char w1, w2; int n1, n2;
      scanf("%c%d %c%d", &w1, &n1, &w2, &n2);
      if(w1 == 'C'){
        cat.push_back(ii(n1, n2));
      }else dog.push_back(ii(n1, n2));
    }
    int cs = (int) cat.size();
    int ds = (int) dog.size();
    
    AdjList.assign(cs + ds + 2, vi());    
    
    for(int i = 0; i < cs; i++){
      for(int j = 0; j < ds; j++){
        if(cat[i].first == dog[j].second || dog[j].first == cat[i].second){
          AdjList[i].push_back(j);
        }
      }
    }
    
    int MCBM = 0;
    match.assign(cs + ds + 2, -1);   
    for (int l = 0; l < cs; l++) { 
      vis.assign(cs + ds + 2, 0);           
      MCBM += Aug(l);
    }
    printf("%d\n", v - MCBM);
    
  }
  return 0;
}
