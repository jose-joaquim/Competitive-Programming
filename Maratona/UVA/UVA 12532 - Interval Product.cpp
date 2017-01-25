//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3977
//THIS QUESTION IS THE SAME AS IN URI 1301 - https://www.urionlinejudge.com.br/judge/pt/problems/view/1301
//ESSA QUESTÃO É A MESMA QUE EM URI 1301 - https://www.urionlinejudge.com.br/judge/pt/problems/view/1301
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
private: vi st, A;            
  int n;
  int left (int p) { return p << 1; }    
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R){
    if(L == R){
      st[p] = A[L];
    }else{
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      st[p] = st[left(p)] * st[right(p)];      
    }
    
  }

  int prod(int p, int L, int R, int i, int j){
    if(i > R || j < L) return 1;

    if(L >= i && R <= j) return st[p];

    int mid = (L + R) / 2;
    int p1 = prod(left(p), L, mid, i, j);
    int p2 = prod(right(p), mid + 1, R, i, j);
    
    return p1 * p2;
  }

  int update_point(int p, int L, int R, int idx, int new_value){
    int i = idx, j = idx;

    if(i > R || j < L){ return st[p]; }
    if(i == L && j == R){
      A[i] = new_value;
      return st[p] = new_value;
    }
    int mid = (L + R) / 2;
    int p1 = update_point(left(p), L, mid, idx, new_value);
    int p2 = update_point(right(p), mid + 1, R, idx, new_value);

    return st[p] = st[left(p)] * st[right(p)];
  }

public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();            
    st.assign(4 * n, 0);            
    build(1, 0, n - 1);
  }

  int prod(int i, int j) { return prod(1, 0, n - 1, i, j); }  // overloading

  int update_point(int idx, int new_value) {
    return update_point(1, 0, n - 1, idx, new_value); }
};

int n, k;
int S[100005];

int value(int x){ return x > 0 ? 1 : (x < 0 ? -1 : 0); }
char signal(int x){ return x > 0 ? '+' : (x < 0 ? '-' : '0'); }

int main(){
  while(scanf("%d %d", &n, &k) != EOF){
    for(int i = 0; i < n; i++){
      int v; scanf("%d", &v);
      S[i] = value(v);
    }
    vi A(S, S + n);
    SegmentTree st(A);
    for(int j = 0; j < k; j++){
      cin.ignore();
      string op; int L, R, v;
      cin >> op;
      scanf("%d %d", &L, &R);
      if(op[0] == 'C'){ 
        st.update_point(L-1, value(R));
      }else{
        int ans = st.prod(L-1, R-1);
        printf("%c", signal(st.prod(L-1, R-1)));
      }
    }
    printf("\n");  
  }
  return 0;
}
