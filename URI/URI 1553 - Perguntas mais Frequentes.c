#include <stdio.h>
#include <string.h>

int main(){
  int n, k;
  while(scanf("%d %d", &n, &k) && n){
    int A[101];
    memset(A, 0, sizeof A);
    int i;
    for(i = 0; i < n; i++){
      int u; scanf("%d", &u);
      A[u]++;
    }
    int ans = 0;
    
    for(i = 1; i <= 100; i++)
      if(A[i] >= k) ans++;

    printf("%d\n", ans);
  }
}
