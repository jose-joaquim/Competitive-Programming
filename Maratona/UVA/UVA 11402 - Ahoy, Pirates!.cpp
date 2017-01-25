//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class SegmentTree{
private: vi A, lazy, st;
  int n;
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
  
  void propagation(int p, int L, int R){
    if(lazy[p] == 1){//setar todo mundo pra 1
      st[p] = R - L + 1;
      if(L != R) lazy[left(p)] = lazy[right(p)] = 1;
    }else if(lazy[p] == 2){//setar todo mundo pra 0
      st[p] = 0;
      if(L != R) lazy[left(p)] = lazy[right(p)] = 2;
    }else if(lazy[p] == 3){//inverter todos no intervalo
      st[p] = (R - L + 1) - st[p];
      if(L != R){
        if(lazy[left(p)] == 0){
          lazy[left(p)] = 3;
        }else{
          if(lazy[left(p)] == 1) lazy[left(p)] = 2;
          else if(lazy[left(p)] == 2) lazy[left(p)] = 1;
          else if(lazy[left(p)] == 3) lazy[left(p)] = 0;
        }

        if(lazy[right(p)] == 0){
          lazy[right(p)] = 3;
        }else{
          if(lazy[right(p)] == 1) lazy[right(p)] = 2;
          else if(lazy[right(p)] == 2) lazy[right(p)] = 1;
          else if(lazy[right(p)] == 3) lazy[right(p)] = 0;
        }
      }
    }
    lazy[p] = 0;
  }
  
  int query(int p, int L, int R, int i, int j){
    
    if(lazy[p] != 0){
      propagation(p, L, R);
    }
    if(i > R || j < L) return 0;
    if(L >= i && R <= j) return st[p];

    int mid = (L + R)/2;
    int p1 = query(left(p), L, mid, i, j);
    int p2 = query(right(p), mid + 1, R, i, j);

    return p1 + p2;
  }
  
  void ativa(int p, int L, int R, int i, int j){
    if(lazy[p] != 0) propagation(p, L, R);
    if(i > R || j < L) return;
    
    if(L >= i && R <= j){//ativa os bits desse intervalo
      st[p] = R - L + 1;
      if(L != R) lazy[left(p)] = lazy[right(p)] = 1;
      return;
    }

    int mid = (L + R) / 2;
    ativa(left(p), L, mid, i, j);
    ativa(right(p), mid + 1, R, i, j);

    st[p] = st[left(p)] + st[right(p)];
  }
  
  void desativa(int p, int L, int R, int i, int j){
    if(lazy[p] != 0) propagation(p, L, R);
    if(i > R || j < L) return;
    
    if(L >= i && R <= j){//desativa os bits desse intervalo
      st[p] = 0;
      if(L != R) lazy[left(p)] = lazy[right(p)] = 2;
      return;
    }

    int mid = (L + R) / 2;
    desativa(left(p), L, mid, i, j);
    desativa(right(p), mid + 1, R, i, j);

    st[p] = st[left(p)] + st[right(p)];
  }
  
  void flip(int p, int L, int R, int i, int j){
    if(lazy[p] != 0) propagation(p, L, R);
    if(i > R || j < L) return;
    
    if(L >= i && R <= j){//flip os bits desse intervalo
      st[p] = (R - L + 1) - st[p];
      if(L != R){
        if(lazy[left(p)] == 0){
          lazy[left(p)] = 3;
        }else{
          if(lazy[left(p)] == 1) lazy[left(p)] = 2;
          else if(lazy[left(p)] == 2) lazy[left(p)] = 1;
          else if(lazy[left(p)] == 3) lazy[left(p)] = 0;
        }

        if(lazy[right(p)] == 0){
          lazy[right(p)] = 3;
        }else{
          if(lazy[right(p)] == 1) lazy[right(p)] = 2;
          else if(lazy[right(p)] == 2) lazy[right(p)] = 1;
          else if(lazy[right(p)] == 3) lazy[right(p)] = 0;
        }
      }
      return;
    }

    int mid = (L + R) / 2;
    flip(left(p), L, mid, i, j);
    flip(right(p), mid + 1, R, i, j);

    st[p] = st[left(p)] + st[right(p)];
  }
  
public:
  SegmentTree(const vi &_A){
    A = _A; n = (int) A.size();
    st.assign(n * 4, 0);
    lazy.assign(n * 4, 0);
    build(1, 0, n - 1);
  }

  int query(int i, int j){ return query(1, 0, n - 1, i, j); }
  void ativa(int i, int j){ ativa(1, 0, n - 1, i, j); }
  void desativa(int i, int j){ desativa(1, 0, n - 1, i, j); }
  void flip(int i, int j){ flip(1, 0, n - 1, i, j); }
  
};

int main(){
  int T; scanf("%d", &T);
  for(int cs = 1; cs <= T; cs++){
    int m; scanf("%d", &m);
    string state = "";
    for(int i = 0; i < m; i++){
      cin.ignore();
      int r; string s;
      cin >> r >> s;
      for(int j = 0; j < r; j++) state += s;
    }
    vi Ax;
    for(int i = 0; i < (int) state.size(); i++) Ax.push_back(state[i] - '0');
    SegmentTree st(Ax);
    int q; scanf("%d", &q);
    printf("Case %d:\n", cs);
    int qs = 1;
    for(int i = 0; i < q; i++){
      cin.ignore();
      char op; int u, v;
      scanf("%c %d %d", &op, &u, &v);
      if(op == 'S'){
        printf("Q%d: %d\n", qs++, st.query(u, v));
      }else{
        if(op == 'F') st.ativa(u, v);
        if(op == 'E') st.desativa(u, v);
        if(op == 'I') st.flip(u, v);
      }
    }
  }  
  return 0;
}
