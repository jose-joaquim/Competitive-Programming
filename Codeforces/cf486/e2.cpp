#include <cstring>
#include<unordered_set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> ii;
typedef pair<string, long long> sip;

//const int MAXN = 2 * 1e5 + 2;

string number;
int rightmost[10];

bool check(string &a) {
  int sz = int(a.size());
  if ((a[sz - 2] == '2' && a[sz - 1] == '5') ||
      (a[sz - 2] == '5' && a[sz - 1] == '0') ||
      (a[sz - 2] == '7' && a[sz - 1] == '5') ||
      (a[sz - 2] == '0' && a[sz - 1] == '0'))
    return true;

  return false;
}

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif

  memset(rightmost, -1, sizeof rightmost);
  cin >> number;
  
  for (int i = 0; i < int(number.size()); i++) {
    rightmost[number[i] - '0'] = i;
  }

  for (int i = int(number.size()) - 1; i >=  0; i--) {
    for (int j = int(number.size()) - 1; j > i; j--) {
      
    }
  }

  for (int i : rightmost) {
    cout << i << " ";
  } cout << endl;
  
  return 0;
}
