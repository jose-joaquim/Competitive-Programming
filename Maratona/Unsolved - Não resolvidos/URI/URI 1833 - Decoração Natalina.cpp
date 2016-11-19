#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

const int REMOVER = 30;
const int TROCAR = 60;
const int NOVA = 150;

int t, r, m, n;
int memo[505][505];
vector<string> wrong, right;

double solve(){


  return 0;
}



int main(){
  scanf("%d", &t);
  for(int qq = 1; qq <= t; qq++){
    wrong.clear(); rigth.clear();
    memset(memo, 0, sizeof memo);
    scanf("%d %d", &r, &m);
    for(int i = 0; i < m; i++){
      string u; cin >> u;
      wrong.push_back(u);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      string u; cin >> u;
      right.push_back(u);
    }

    printf("Caso #%d: R$ .2lf\n", qq, solve());
  }
  return 0;
}
