#include <limits>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

#define len(x) ((int)x.size())

typedef vector<int> vi;

int main() {
  string a; cin >> a;
  int appear[27];
  map<int, int> appear;
  int sz = len(a);
  for (int i = 0; i < sz; i++) {
    appear[a[i]] += 1;
  }

  int ans = numeric_limit<int>::max();
  string palavra = "Bulbasaur";
  for (int i = 0; i < len(palavra); i++) {
    
  }
  return 0;
}
