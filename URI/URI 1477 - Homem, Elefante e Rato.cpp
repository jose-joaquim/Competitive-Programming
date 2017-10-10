//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1477
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<iii> viii;

class SegmentTree{
private: viii st; vi A, lazy;
  int n;
  int left(int p){ return p << 1; }
  int right(int p){ return (p << 1) + 1; }
  int count(int n){ return n % 3; } //pra contar os loops

  void propagation(int p, int L, int R){
    int n_ahead = count(lazy[p]);
    iii &ob = st[p];
    if(n_ahead == 1){
      swap(ob.second.first, ob.second.second);//z com y
      swap(ob.second.first, ob.first);//y com x
    }else if(n_ahead == 2){
      swap(ob.second.first, ob.second.second);//z com y
      swap(ob.first, ob.second.second);//x com z
    }
    if(L != R){
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }

  void build(int p, int L, int R){
    if(L == R){
      st[p] = iii(1, ii(0, 0));
    }else{

      int mid = (L + R) / 2;
      build(left(p), L, mid);
      build(right(p), mid + 1, R);

      iii b1 = st[left(p)], b2 = st[right(p)];
      st[p].first = b1.first + b2.first;
    }
  }
  
  iii query(int p, int L, int R, int i, int j){
    if(lazy[p] != 0) propagation(p, L, R);
    if(i > R || j < L) return iii(0, ii(0, 0));

    if(L >= i && R <= j){ return st[p]; }

    int mid = (L + R) / 2;
    iii q1 = query(left(p), L, mid, i, j);
    iii q2 = query(right(p), mid + 1, R, i, j);

    iii ret;
    ret.first = q1.first + q2.first;
    ret.second.first = q1.second.first + q2.second.first;
    ret.second.second = q1.second.second + q2.second.second;
    return ret;
  }

  void strategy(int p, int L, int R, int i, int j){
    if(lazy[p] != 0) propagation(p, L, R);
    if(i > R || j < L) return;

    if(L >= i && R <= j){
      iii &ob = st[p];

      swap(ob.second.first, ob.second.second);
      swap(ob.first, ob.second.first);
      if(L != R){
        lazy[left(p)] += 1;
        lazy[right(p)] += 1;
      }
      return;
    }

    int mid = (L + R) / 2;
    strategy(left(p), L, mid, i, j);
    strategy(right(p), mid + 1, R, i, j);

    iii &o = st[p], &x1 = st[left(p)], &x2 = st[right(p)];

    o.first = x1.first + x2.first;
    o.second.first = x1.second.first + x2.second.first;
    o.second.second = x1.second.second + x2.second.second;
  }

public:
  SegmentTree(int size){
    lazy.assign(size * 4, 0);
    st.assign(size * 4, iii());
    n = size;
    build(1, 0, n - 1);
  }

  iii query(int i, int j){ return query(1, 0, n - 1, i, j); }
  void strategy(int i, int j){ strategy(1, 0, n - 1, i, j); }
};

int main(){
  int n, m;
  while(scanf("%d %d", &n, &m) != EOF){
    SegmentTree st(n);
    for(int i = 0; i < m; i++){
      cin.ignore();
      char op; int u, v;
      scanf("%c %d %d", &op, &u, &v);
      if(op == 'C'){
        iii ans = st.query(u - 1, v - 1);
        printf("%d %d %d\n", ans.first, ans.second.first, ans.second.second);
      }else{
        st.strategy(u - 1, v - 1);
      }
    }
    printf("\n");
  }
  return 0;
}
