//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2400
#include <bits/stdc++.h>

#define LSOne(S) (S & -(S))

using namespace std;

int A[100005], B[100005], bit[100005], n;
long long ans = 0;

void adjust(int k, int v) {            
  for (; k < n; k += LSOne(k)) bit[k] += v; }

int rsq(int b) {                                  
  int sum = 0; for (; b; b -= LSOne(b)) sum += bit[b];
  return sum; }

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
    B[i] = A[i];
  }
  sort(B, B + n);
  for(int i = 0; i < n; i++){
    int idx = int(lower_bound(B, B + n, A[i]) - B);
    A[i] = idx + 1;
  }
  for(int i = n - 1; i >= 0; i--){
    long long x = rsq(A[i] - 1);
    ans += x;
    adjust(A[i], 1);
  }
  printf("%lld\n", ans);
  return 0;
}
