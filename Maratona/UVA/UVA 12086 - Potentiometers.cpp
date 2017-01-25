//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3238
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n;
int S[200010];

class SegmentTree{
private: vi st, A;
  int sz;
  int left(int p){ return p << 1; }
  int right(int p){ return (p << 1) + 1; }

  void build(int p, int L, int R){
    if(L == R){
      st[p] = A[L];
    }else{
      int mid = (L + R) / 2;

      build(left(p), L, mid);
      build(right(p), mid + 1, R);

      st[p] = st[left(p)] + st[right(p)];
    }
  }

  int sumq(int p, int L, int R, int i, int j){
    if(i > R || j < L) return 0;

    if(L >= i && R <= j) return st[p];

    int mid = (L + R) / 2;
    
    int s1 = sumq(left(p), L, mid, i, j);
    int s2 = sumq(right(p), mid + 1, R, i, j);
    
    return s1 + s2;
  }
  
  int update_point(int p, int L, int R, int idx, int new_value){
    int i = idx, j = idx;

    if(i > R || j < L) return 0;
    if(i == L && j == R){
      A[i] = new_value;
      return st[p] = new_value;
    }

    int mid = (L + R) / 2;
    int s1 = update_point(left(p), L, mid, idx, new_value);
    int s2 = update_point(right(p), mid + 1, R, idx, new_value);

    return st[p] = st[left(p)] + st[right(p)];
  }

public:
  SegmentTree(const vi &_A){
    A = _A; sz = (int) A.size();
    st.assign(sz * 4, 0);
    build(1, 0, sz - 1);    
  }

  int sumq(int L, int R){ return sumq(1, 0, sz - 1, L, R); }
  int update_point(int idx, int new_value) {
    return update_point(1, 0, sz - 1, idx, new_value); }
  
};

int main(){
  bool go = false;
  int cs = 0;
  while(scanf("%d", &n) && n){
    go ? printf("\n") : (go = true);
    for(int i = 0; i < n; i++) scanf("%d", &S[i]);
    vi Ax(S, S+n);
    SegmentTree st(Ax);
    char op[4]; int u, v;
    printf("Case %d:\n", ++cs);
    cin.ignore();
    //printf("aiosdna\n");
    while(scanf("%s", op) && op[0] != 'E'){
      scanf("%d %d", &u, &v);
      cin.ignore();
      if(op[0] == 'M'){
        printf("%d\n", st.sumq(u - 1, v - 1));
      }else{
        st.update_point(u - 1, v);
      }
    }
  }
  return 0;
}
