#include <cstdio>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
  map<string, int> m;
  m["Tetrahedron"] = 4;
  m["Cube"] = 6;
  m["Octahedron"] = 8;
  m["Dodecahedron"] = 12;
  m["Icosahedron"] = 20;
  int n; cin >> n;
  int ans = 0;
  for(int i = 0; i < n; i++){
    string a; cin >> a;
    ans += m[a];
  }
  cout << ans << endl;
  return 0;
}
