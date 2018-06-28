#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n; cin >> n;
  int arr[2 * n];
  for (int i =0 ; i < 2 * n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + (2 * n));
  int p = 2 * n / 2;
  //printf("%d %d\n", n, p);
  for (int i = 0; i < p; i++) {
    for (int j = p; j < 2 * n; j++) {
      //printf("%d %d\n", arr[i], arr[j]);
      if (arr[i] >= arr[j]) {
        printf("NO\n");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}
