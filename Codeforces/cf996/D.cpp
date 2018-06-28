#include <deque>
#include <limits>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

#define len(x) ((int)x.size())

typedef vector<int> vi;

deque<int> arr;
deque<deque<int> > pos;
int n;


bool verify() {
  for (int i = 0; i < (2 * n) - 1; i += 2) {
    if (arr[i] != arr[i + 1]) {
      return false;
    }
  }

  return true;
}

int main() {
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  cin >> n;
  pos.assign(n + 1, deque<int>());
  deque<int> sum(n + 1, 0);
  for (int i = 0; i < 2 * n; i++) {
    int u; cin >> u;
    //printf("li %d\n", u);
    arr.push_back(u);
    pos[u].push_back(i);
  }
  deque<int> fixed(n + 1, 0);
  if (!verify()) {
    int ans = 0;
    for (int i = 0; i < (2 * n) - 1; i += 1) {
      if (fixed[arr[i]]) {
        sum[i + 1] = sum[i];
        continue;
      }
      
      if (arr[i] != arr[i + 1]) {
        //printf("wrong %d %d at %d and %d\n", arr[i], arr[i + 1], i, i + 1);
        //printf("     second %d is at %d\n", arr[i], pos[arr[i]][1]); 
        sum[i + 1] = sum[i] + 1;
        //printf("will add %d - %d = %d\n", (pos[arr[i]][1] - i - 1), sum[i], (pos[arr[i]][1] - i - 1) - sum[i]);
        ans += (pos[arr[i]][1] - i - 1) - sum[i];
        fixed[arr[i]] = true;
      } else {
        fixed[arr[i]] = true;
      }
    }
    cout << ans << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}
