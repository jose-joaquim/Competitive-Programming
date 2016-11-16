#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int ks[200010];
int l[200010];
int r[200010];
int mem[200010][3];

void init(){
  memset(ks, 0, sizeof ks);
  memset(l, 0, sizeof l);
  memset(r, 0, sizeof r);
  memset(mem, -1, sizeof mem);
}

int dp(int i, int flag){
  if (i  > m ) return 0;
  int p1 = ks[l[i]];
  int p2 = ks[r[i]];
  if (mem[i][flag] != -1) return mem[i][flag]; 

  if (p1 != p2) {
    ks[l[i]] = p2;
    int res1 = 1 + dp(i + 1, 0);
    ks[l[i]] = p1;

    ks[r[i]] = p1;
    int res2 = 1 + dp(i + 1, 1);
    ks[r[i]] = p2;
    
    return mem[i][flag] = min(res1, res2);
  }else{
    return mem[i][flag] = dp(i+1, 2);
  }
}

int main(){
  while (scanf("%d %d %d", &n, &m, &k) != EOF) {
    init();
    for (int i=1; i <= n; i++) scanf("%d",&ks[i]);
    for (int i=1; i <= m; i++) scanf("%d %d",&l[i], &r[i]);
    printf("%d\n",dp(1,0));
  }
  return 0;
}
