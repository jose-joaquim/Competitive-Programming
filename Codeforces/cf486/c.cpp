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

int k;
vector<int> seq_sums;
vector<vector<int> > seqs;

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  
  cin >> k;
  vector<pair<int, pair<int, int> > > ws;
  for (int s = 0; s < k; s++) {
    int ni; cin >> ni;
    int sum = 0;
    vector<int> arr;
    for (int i = 0; i < ni; i++) {
      int u; cin >> u;
      sum += u;
      arr.push_back(u);
    }

    for (int i = 0; i < ni; i++) {
      int aux = sum - arr[i]; // aux equals to accumulative sum without arr[i]
      ws.push_back(make_pair(aux, make_pair(s, i)));
    }
  }

  sort(ws.begin(), ws.end());
  //stable_sort(ws.begin(), ws.end());

  for (int i = 0; i < int(ws.size()) - 1; i++) {
    if (ws[i].first == ws[i + 1].first && (ws[i].second.first != ws[i + 1].second.first)) {
      cout << "YES\n";
      cout << ws[i + 1].second.first + 1 << " " << ws[i + 1].second.second + 1 << endl;
      cout << ws[i].second.first + 1 << " " << ws[i].second.second + 1 << endl;
      return 0;
    }
  }

  cout << "NO\n"; 
  return 0;
}
