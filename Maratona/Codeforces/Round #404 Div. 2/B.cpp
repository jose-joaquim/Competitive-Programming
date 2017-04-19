#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d", &n);
  string s;
  int l,r,maiorX =0, menorX = 1000000002;
  for(int i=0;i<n;i++){
    scanf("%d%d", &l, &r);
    if(r < menorX) menorX = r;
    if(l>maiorX)maiorX = l;
  }
  int m, maiorP = 0, menorP = 1000000002;
  scanf("%d", &m);
 
  for(int i=0;i<m;i++){
    scanf("%d%d", &l, &r);
    if(r < menorP) menorP = r;
    if(l > maiorP) maiorP = l;
  }
 
  int r1 = maiorP - menorX;
  int r2 = maiorX - menorP;
  r2 = max(r1, r2);
 
  if(r2 <=0) printf("0\n");
  else printf("%d\n", r2);
 
  return 0;
}
