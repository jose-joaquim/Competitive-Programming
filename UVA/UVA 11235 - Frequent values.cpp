//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2176
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int n, q;
vi S;

class SegmentTree{
private: vi st, A;
  int n;
  int left(int p){ return p << 1; }
  int right(int p){ return (p << 1) + 1; }

  void build(int p, int L, int R){
    if(L == R){
      st[p] = L;
    }else{
      int mid = (L + R) / 2;
      
      build(left(p), L, mid);
      build(right(p), mid + 1, R);

      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] >= A[p2]) ? p1 : p2;
    }
  }

  int rmaxq(int p, int L, int R, int i, int j){
    if(i > R || j < L) return -1;
    if(L >= i && R <= j) return st[p]; 

    int mid = (L + R) / 2;
    
    int p1 = rmaxq(left(p), L, mid, i, j);
    int p2 = rmaxq(right(p), mid + 1, R, i, j);

    if(p1 == -1) return p2;
    if(p2 == -1) return p1;

    return (A[p1] >= A[p2]) ? p1: p2;
  }

public:
  SegmentTree(const vi &_A){
    A = _A; n = (int) A.size();
    st.assign(4*n, 0);
    build(1, 0, n - 1);
  }

  int rmaxq(int i, int j){ return rmaxq(1, 0, n - 1, i, j); }
  
};

int main(){
  while(scanf("%d", &n) && n){
    scanf("%d", &q);
    S.clear();
    for(int i = 0; i < n; i++){
      int u; scanf("%d", &u);
      S.push_back(u);
    }
    int A[100005];
    for(int i = 0; i < n; ){
      auto par = equal_range(S.begin(), S.end(), S[i]);
      int tp = par.second - par.first;
      for(int j = i; j < i + tp; j++){
        A[j] = tp;
      }
      i += tp;
    }
    vi Ax(A, A + n);
    SegmentTree st(Ax);
    for(int i = 0; i < q; i++){
      int u, v, j, k; scanf("%d %d", &u, &v);
      u--; v--;
      if(u == v){ puts("1"); continue; }
      int temp1 = u, temp2 = v;
      while(S[u] == S[temp1] && temp1 <= v) temp1++;
      while(S[v] == S[temp2] && temp2 >= u) temp2--;
      int freq1 = temp1 - u, freq2 = v - temp2;
      printf("%d\n", max(freq1, max(freq2, A[st.rmaxq(temp1, temp2)])));
    }
  }
  return 0;
}
