//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1417
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

typedef vector<int> vi;

int h, r;
vi grau;
vector<vi> AdjList;

bool cmp(int a, int b){
  return b < a;
}

int main(){
  while(scanf("%d %d", &h, &r) && (h || r)){
    grau.assign(h + 1, 0);
    AdjList.assign(h + 1, vi());
    for(int i = 0; i < r; i++){
      int u, v; scanf("%d %d", &u, &v);
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
      grau[u]++; grau[v]++;
    }
    grau[0] = 100000000;
    sort(grau.begin(), grau.end(), cmp);
    int m = -1;
    for(int i = 0; i < (int) grau.size(); i++){
      if(grau[i] < i - 1) continue;
      m = max(m, i);
    }
    int sum1 = 0, sum2 = m*(m - 1);
    for(int i = 1; i <= m; i++){
      sum1 += grau[i];
    }
    for(int i = m + 1; i < (int) grau.size(); i++){
      sum2 += grau[i];
    }
    puts((sum1 == sum2) ? "Y" : "N");
  }
  return 0;
}
