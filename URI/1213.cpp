#include <limits>
#include <bitset>
#include <cstring>
#include <sstream>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define len(x) ((int)x.size())
typedef vector<int> vi;

const int MAXN = 1e5 + 2;

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif

  long long int n, l, c;
 
  while(cin >> n){
    l = 1;c = 1;
 
    while(l % n != 0){
      l = (10 * l + 1) % n;
      c++;
    }
    
    cout << c << '\n';
  }
  return 0;
}
