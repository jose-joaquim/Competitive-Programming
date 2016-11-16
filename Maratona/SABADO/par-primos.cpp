#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  long long a, b;
  while(scanf("%lld %lld", &a, &b)){
    if(!a && !b) break;
    int l = ceil(sqrt(a)), r = sqrt(b);
    long long ans = b - a + 1 - (r - l + 1);
    printf("%lld\n", ans);
  }
  return 0;
}
