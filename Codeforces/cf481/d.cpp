#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 1;

int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int u; cin >> u;
    arr.push_back(u);
  }
  
  int ans = MAXN + 1;
  for (int x1 = -1; x1 <= 1; x1++) {
    for (int y1 = -1; y1 <= 1; y1++) {
      int changes = (x1 != 0) + (y1 != 0);
      //printf("%d %d", x1, y1);
      vector<int> aux = arr;
      aux[0] = arr[0] + x1;
      aux[1] = arr[1] + y1;
      int razao = aux[1] - aux[0];
      //printf(" razao %d ", razao);
      for (int j = 2; j < n; j++) {
        if (aux[j] - aux[j - 1] - 1 == razao) {
          aux[j] -= 1;
          changes += 1;
        } else if (aux[j] - aux[j - 1] + 1 == razao) {
          aux[j] += 1;
          changes += 1;
        } else if (aux[j] - aux[j - 1] == razao) {
          continue;
        } else {
          changes = MAXN + 1;
          break;
        }
      }
      //printf(" => %d\n", changes);
      ans = min(ans, changes);
    }
  }

  cout << (ans == MAXN + 1 ? -1 : ans) << '\n';
  return 0;
}
