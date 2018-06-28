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
  for (int i = 0; i < 2 * n; i++) {
    int u; cin >> u;
    arr.push_back(u);
    pos[u].push_back(i);
  }
  if (!verify()) {
    int ans = 0;
    while(!verify()) {
      for (int i = 0; i < (2 * n) - 1; i += 2) {
        if (arr[i] != arr[i + 1]) {
          //printf("%d %d on %d and %d\n", arr[i], arr[i + 1], i, i + 1);
          int where = pos[arr[i]][1];
          //printf("the second %d is in %d\n", arr[i], where);
          for (int k = where; k > i + 1; k--) {
            //printf("        changed %d (in %d) with %d (in %d)\n", arr[k], k, arr[k - 1], k -1);
            swap(arr[k], arr[k - 1]);
            ans++;
          }
          //ans--;
          pos.assign(n + 1, deque<int>());
          for (int i = 0; i < 2 * n; i++) {
            pos[arr[i]].push_back(i);
          }
          break;
        }
      }
      /*printf("array now is:\n");
      for (int x : arr) {
        cout << x << " ";
      } cout << endl;*/
    }
    cout << ans << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}
