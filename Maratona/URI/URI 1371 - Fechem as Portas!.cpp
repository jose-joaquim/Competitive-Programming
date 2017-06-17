#include <cstdio>
#include <iostream>

using namespace std;

int gcd(int a, int b){ return a == 0 ? b : gcd(b, a % b); }
int mmc(int a, int b){ return a * (b / gcd(a, b)); }

const int MAXN = 25000001;
int n;
int A[MAXN];

int main(){
  for(int i = 1; i <= MAXN; i++){
    A[i - 1] = i*i;
  }
  while(scanf("%d", &n) && n){
    bool brk = false;
    for(int i = 0; A[i] <= n; i++){
      if(brk) printf(" "); else brk = true;
      printf("%d", A[i]);
    }
    puts("");
  }
  return 0;
}
