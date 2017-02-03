//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2185
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int N, M;

class SegmentTree{
private: vi A, st, lazy;
  int n;
  int left(int p){ return (p << 1); }
  int right(int p){ return (p << 1) + 1; }

  void build(int p, int L, int R){
    if(L == R){
      st[p] = A[L];
    }else{

      int mid = (L + R) / 2;
      build(left(p), L, mid);
      build(right(p), mid + 1, R);

      st[p] = st[left(p)] xor st[right(p)];
    }
  }

  void propagation(int p, int L, int R){
    if((R - L + 1) % 2 == 0){
      st[p] = 0;
    }else st[p] = lazy[p];
    if(L != R){
      lazy[left(p)] = lazy[right(p)] = lazy[p];
    }
    lazy[p] = -1;
  }

  int query(int p, int L, int R, int i, int j){
    if(lazy[p] != -1) propagation(p, L, R);
    if(i > R || j < L) return 0;

    if(L >= i && R <= j) return st[p];

    int mid = (L + R) / 2;
    int p1 = query(left(p), L, mid, i, j);
    int p2 = query(right(p), mid + 1, R, i, j);

    return p1 xor p2;    
  }

  void update(int p, int L, int R, int i, int j, int value){
    if(lazy[p] != -1) propagation(p, L, R);
    if(i > R || j < L) return;

    int mid = (L + R) / 2;
    
    if(L >= i && R <= j){
      if((R - L + 1) % 2 == 0){
        st[p] = 0;
      }else st[p] = value;
      
      if(L != R){
        lazy[left(p)] = lazy[right(p)] = value;
      }      
      return;
    }

    
    update(left(p), L, mid, i, j, value);
    update(right(p), mid + 1, R, i, j, value);

    st[p] = st[left(p)] xor st[right(p)];
  }
public:
  SegmentTree(const vi &_A){
    A = _A; n = (int) A.size();
    st.assign(n * 4, 0);
    lazy.assign(n * 4, -1);
    build(1, 0, n - 1);
  }

  int query(int i, int j){ return query(1, 0, n - 1, i, j); }
  int update(int i, int j, int value){ update(1, 0, n - 1, i, j, value); }
};

int main(){
  while(scanf("%d %d", &N, &M) != EOF){
    vi S;
    for(int i = 0; i < N; i++){
      int u; scanf("%d", &u);
      S.push_back(u);
    }
    SegmentTree st(S);
    for(int j = 0; j < M; j++){
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      st.update(u - 1, v - 1, w);
      puts(st.query(0, N - 1) ? "Possivel" : "Impossivel");
    }
  }
  return 0;
}
