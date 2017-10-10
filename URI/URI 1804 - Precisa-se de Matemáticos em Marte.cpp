//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1804
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define LSOne(S) (S & (-S))

int n;
vector<int> A;

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) {
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

int main(){
  while(scanf("%d", &n) != EOF){
    A.assign(n+1, 0);
    FenwickTree ft(n);
    for(int i = 1; i <= n; i++){
      int u; scanf("%d", &u);
      A[i] = u;
      ft.adjust(i, u);
    }
    char op;
    cin.ignore();
    while(scanf("%c", &op) != EOF){
      int u;
      scanf("%d", &u);
      if(op == 'a'){
        ft.adjust(u, -A[u]);
        A[u] = 0;
      }else{
        printf("%d\n", ft.rsq(u) - A[u], ft.rsq(u));
      }
      cin.ignore();
    }
  }
  return 0;
}
