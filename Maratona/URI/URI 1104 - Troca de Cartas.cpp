//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1104
#include <bits/stdc++.h>

using namespace std;

int a, b;
set<int> s_a, s_b;

int solve(set<int> &con, set<int> &rec){
  int ans = 0;

  while(!con.empty()){
    int value = *con.begin();
    if(rec.find(value) == rec.end()){
      ans++;
    }
    con.erase(con.begin());
  }  
  
  return ans;
}

int main(){
  while(scanf("%d %d", &a, &b) && (a || b)){
    s_a.clear(); s_b.clear();
    for(int i = 0; i < a; i++){
      int u; scanf("%d", &u);
      s_a.insert(u);
    }
    for(int i = 0; i < b; i++){
      int u; scanf("%d", &u);
      s_b.insert(u);
    }
    printf("%d\n", s_a.size() > s_b.size() ? solve(s_b, s_a) : solve(s_a, s_b));
  }
  return 0;
}
