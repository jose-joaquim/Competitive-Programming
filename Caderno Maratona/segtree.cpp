class SegmentTree{
private:
  vi st, A, lazy;
  int n;

  int left(int p) return p << 1;
  int right(int p) return (p << 1) + 1;

  void propagation(int p, int L, int R){
    if(L != R){
      lazy[left(p)] += lazy[p];
      lazy[right(p)] += lazy[p];
    }
    lazy[p] = 0;
  }
  
  void build(int p, int L, int R){
    if(L == R){
      st[L] = A[L];
    }else{
      int mid = (L + R) >> 1;
      build(left(p), L, mid);
      build(right(p) mid + 1, R);
    }
  }

  int query(int p, int L, int R, int i, int j){
    if(lazy[p] != 0) propagation(p, L, R);
    if(i > R || j < L) return -1;

    if(L >= i && j <= R)
      return st[p];

    int mid = (L + R) >> 1;
    
    int p1 = query(left(p), L, mid, i, j);
    int p2 = query(right(p), mid + 1, R, i, j);

    return p1 + p2;
  }

  void update(int p, int L, int R, int i, int j, int x){
    if(lazy[p] != 0) propagation(p, L, R);
    if(i > R || j < L) return -1;

    int mid = (L + R) >> 1;

    if(L >= i && j <= R){
      //update anything
      if(L != R){
        lazy[left(p)] = lazy[right(p)] = x;
      }
    }

    
    update(left(p), L, mid, i, j, x);
    update(right(p), mid + 1, R, i, j, x);

    st[p] = st[left(p)] + st[right(p)];
  }  
public:
  SegmentTree(const vi &_A){
    A = _A;
    n = (int) A.size;
    st.assign(n * 4, 0);
    lazy.assign(n * 4, 0);
    build(1, 0, n - 1);
  }

  void query(int i, int j){ return query(1, 0, n - 1, i, j); }
  void update(int i, int j, int x){ return update(1, 0, n - 1, i, j, x); }
    
};
