/* Dividir seu array de tamanho n em pedacos de tamanho L

   a[0] a[1] | a[2] a[3] | a[4] a[5] | ... a[n]
   pedaco 0    pedaco 1    pedaco 2

   Uma consulta eh um intervalo [l, r]. Ordenamos as consultas por (pedaco_l, r).

   Consulta zero demorou tempo O(n log n).
   Ja processamos ate a consulta i (de acordo com a ordem acima).

   Se a consulta i+1 aumenta pedaco_l, entao demora tempo O(n log n). Mas isso so acontece n/L vezes

   Todas as consultas (exceto a primeira) que tem mesmo valor de pedaco_l tem valores crescentes de r.
   Eh necessario, portanto, apenas uma passada no array para tratar todas elas. Para cada pedaco, 
   respondemos todas as consultas desse pedaco em tempo O(n log n) e tem L pedacos.

   n * n/L * log n + L * n * log n

   n/L = L => L = sqrt(n) */

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct query {
  int l;
  int r;
  int pedaco_l;
  int id;
  int ans;
    
  // Tem que verificar que a nao eh menor que a
  // Tem que verificar que a < b < c => a < c
  bool operator<(const query& q) const {
    if (pedaco_l != q.pedaco_l) return pedaco_l < q.pedaco_l;
    return (pedaco_l & 1) ? (r > q.r) : (r < q.r);
  }
};

int rev[30000], a[30000], vals[30000];
int m[30000], qtd;

inline void remove(int val) {
  if (m[val] == 1)
    qtd--;
  m[val]--;
}

inline void add(int val) {
  if (m[val] == 0)
    qtd++;
  m[val]++;
}

int main() {
  int n;
  scanf("%d", &n);
  int L = sqrt(n);
    
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    vals[i] = a[i];
  }
    
  sort(vals, vals+n);
  auto fim = unique(vals, vals+n);
    
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(vals, fim, a[i]) - vals;
        
  int q;
  scanf("%d", &q);
    
  vector<query> v;
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    v.push_back(query{l, r, l/L, i, 0});
  }
  sort(v.begin(), v.end());
    
  int l = 0, r = 0;
  for (int i = 0; i < q; i++) {
    while (l > v[i].l) add(a[l-1]), l--;
    while (r < v[i].r) add(a[r]), r++;
        
    while (l < v[i].l) remove(a[l]), l++;
    while (r > v[i].r) remove(a[r-1]), r--;
        
    v[i].ans = qtd;
  }
    
  for (int i = 0; i < q; i++)
    rev[v[i].id] = i;
        
  for (int i = 0; i < q; i++)
    printf("%d\n", v[rev[i]].ans);
}
