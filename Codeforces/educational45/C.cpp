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

const int MAXN = 3 * 1e5;
int cnt[MAXN];

int get(string &u) {
  //printf("analisando %s, %d\n", u.c_str(), len(u));
  int bal = 0;
  for (int i = 0; i < len(u); i++) {
    if (u[i] == '(') {
      bal++;
    } else {
      bal--;
    }

    //printf("bal eh %d\n", bal);

    if (bal < 0) {
      return -1;
    }
  }

  return bal;
}

string getrev(string &u) {
  string ret = "";
  reverse(u.begin(), u.end());
  for (int i = 0; i < len(u); i++) {
    if (u[i] == '(') {
      ret += ')';
    } else {
      ret += '(';
    }
  }
  return ret;
}

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  int n; cin >> n;

  string arr[MAXN];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    int w = get(arr[i]);
    if (w >= 0) {
      //printf("oi %d\n", w);
      cnt[w]++;
    }
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    string rev = getrev(arr[i]);
    int w = get(rev);
    if (w >= 0) {
      ans += cnt[w];
    }
  }
  
  cout << ans << '\n'; 
  
  return 0;
}
