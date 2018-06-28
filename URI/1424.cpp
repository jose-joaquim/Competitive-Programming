#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    unordered_map<int, vector<int> > arr;
    for (int i = 0; i < n; i++) {
      int u; scanf("%d", &u);
      arr[u].push_back(i + 1);
    }
    while(m--) {
      int k, v; scanf("%d %d", &k, &v);
      if (arr.find(v) != arr.end()) {
        printf("%d\n", (arr[v].size() < k) ? 0 : arr[v][k-1]);
      } else {
        puts("0");
      }
    }
  }
  return 0;
}
