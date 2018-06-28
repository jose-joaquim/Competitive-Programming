#include <algorithm>
#include <map>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> ii;

int n;
vector<string> st;

map<int, vector<string> > sbs;

bool cmp(const string &a, const string &b) {
  return a.size() < b.size();
}

int main(){
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    string u; cin >> u;
    st.push_back(u);
  }

  sort (st.begin(), st.end(), cmp);

  /*for (string u : st) {
    cout << u << '\n';
    }// cout << '\n';*/

  bool ans = true;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (st[i].find(st[j]) == string::npos) {
        ans = false;
        break;
      }
    }
  }

  if (ans) {
    cout << "YES\n";
    for (string u : st) {
      cout << u << '\n';
    }
  } else {
    cout << "NO\n";
  }
  
  return 0;
}
