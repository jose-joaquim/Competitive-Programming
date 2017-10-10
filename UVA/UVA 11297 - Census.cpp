//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2272
#include <bits/stdc++.h>

using namespace std;

#define Max 501
#define INF (1 << 30)
int P[Max][Max];

struct Point {
  int x, y, mx;
  Point() {}
  Point(int x, int y, int mx) : x(x), y(y), mx(mx) {}

  bool operator < (const Point& other) const {
    return mx < other.mx;
  }
};

struct Segtree2d {

  Point T[500000]; 

  int n, m;

 
  void init(int n, int m) {
    this -> n = n;
    this -> m = m;
    build(1, 1, 1, n, m);
  }

  Point build(int node, int a1, int b1, int a2, int b2) {
    if (a1 > a2 or b1 > b2)
      return def();

    if (a1 == a2 and b1 == b2)
      return T[node] = Point(a1, b1, P[a1][b1]);

    T[node] = def();
    T[node] = maxNode(T[node], build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
    T[node] = maxNode(T[node], build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
    T[node] = maxNode(T[node], build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
    T[node] = maxNode(T[node], build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
    return T[node];
  }

  Point query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) {
    if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
      return def();


    if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2)
      return T[node];

    Point mx = def();
    mx = maxNode(mx, query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2) );
    mx = maxNode(mx, query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2) );
    mx = maxNode(mx, query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2) );
    mx = maxNode(mx, query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));

    return mx;
  }

  Point query(int x1, int y1, int x2, int y2) {
    return query(1, 1, 1, n, m, x1, y1, x2, y2);
  }

  Point update(int node, int a1, int b1, int a2, int b2, int x, int y, int value) {
    if (a1 > a2 or b1 > b2)
      return def();

    if (x > a2 or y > b2 or x < a1 or y < b1)
      return T[node];

    if (x == a1 and y == b1 and x == a2 and y == b2)
      return T[node] = Point(x, y, value);

    Point mx = def();
    mx = maxNode(mx, update(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x, y, value) );
    mx = maxNode(mx, update(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x, y, value));
    mx = maxNode(mx, update(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x, y, value));
    mx = maxNode(mx, update(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x, y, value) );
    return T[node] = mx;
  }

  Point update(int x, int y, int value) {
    return update(1, 1, 1, n, m, x, y, value);
  }

  virtual Point maxNode(Point a, Point b) {
    return max(a, b);
  }

  virtual Point def() {
    return Point(0, 0, -INF);
  }
};


struct Segtree2dMin : Segtree2d {
  Point maxNode(Point a, Point b) {
    return min(a, b);
  }

  Point def() {
    return Point(0, 0, INF);
  }
};


Segtree2d Tmax;
Segtree2dMin Tmin;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      scanf("%d", &P[i][j]);
    }
  }

  Tmax.init(n, n);
  Tmin.init(n, n);

  int q; scanf("%d", &q);

  for(int j = 0; j < q; j++){
    cin.ignore(); char c;
    scanf("%c", &c);
    if(c == 'c'){
      int x, y, v;
      scanf("%d %d %d", &x, &y, &v);
      Tmax.update(x, y, v);
      Tmin.update(x, y, v);
    }else{
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      printf("%d %d\n", Tmax.query(x1, y1, x2, y2).mx, Tmin.query(x1, y1, x2, y2).mx);
    }
  }

  return 0;
}
