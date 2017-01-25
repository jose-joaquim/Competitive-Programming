//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3362
#include <bits/stdc++.h>

using namespace std;

int B, S;
int bs[10005], ss[10005];

int main(){
  int cs = 1;
  while(scanf("%d %d", &B, &S) && (B || S)){
    int ans = 0;
    for(int i = 0; i < B; i++) scanf("%d", &bs[i]);
    for(int j = 0; j < S; j++) scanf("%d", &ss[j]);
    sort(bs, bs + B); sort(ss, ss + S);
    
    if(B > S){
      printf("Case %d: %d %d\n", cs, B - S, bs[0]);
    }else{
      printf("Case %d: 0\n", cs, 0);
    }
    cs++;
  }
  return 0;
}
