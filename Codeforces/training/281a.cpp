#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  string w; cin >> w;
  w[0] = toupper(w[0]);
  cout << w << '\n';
  return 0;
}
