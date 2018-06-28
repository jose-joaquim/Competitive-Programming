#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> order(10001, -1);
  vector<int> arr;
  set<int> numbers;
  for (int i = 0; i < n; i++) {
    int u; cin >> u;
    order[u] = i;
    arr.push_back(u);
    numbers.insert(u);
  }  


  cout << numbers.size() << '\n';
  for (int i = 0; i < 10000; i++) {
    if (order[arr[i]] == i) {
      printf("%d ", arr[i]);
    }
  } puts("");
  
  
  /*
  reverse(arr.begin(), arr.end());
  set<int> seen;

  for (int x : arr) {
    if (seen.find(x) == seen.end()) {
      printf("%d ", x);
      seen.insert(x);
    }
  } puts("");
  */
  return 0;
}
