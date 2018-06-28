#include <numeric>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iostream>


using namespace std;

#define len(x) ((int)x.size())

int n, M;
vector<int> state;
vector<int> on, off;
vector<int> sum_on, sum_off;

map<int, pair<int, int> > which;

void printvector(vector<int> &a) {
  for (int x : a) {
    cout << x << " ";
  } cout << '\n';
}

int main() {
#ifndef DEBUG
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  cin >> n >> M;

  state.push_back(0);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int u; cin >> u;
    state.push_back(u);
    if (i % 2 == 1) {
      sum_on.push_back(u - state[i - 1]);
      ans += (u - state[i - 1]);
    } else {
      sum_off.push_back(u - state[i - 1]);
    }
  }
  state.push_back(M);
  if ((n + 1) % 2 == 1) {
    sum_on.push_back(M - state[len(state) - 2]);
  } else {
    sum_off.push_back(M - state[len(state) - 2]);
  }

  map<int, pair<int, int> > d;
  for (int i = 1; i < len(state) - 1; i++) {
    d[state[i]] = make_pair(accumulate(sum_on.begin() + i, sum_on.end(), 0), accumulate(sum_off.begin() + i, sum_off.end(), 0));
    printf("%d %d %d\n", state[i], d[state[i]].first, d[state[i]].second);
  }
  printvector(sum_off);
  printvector(sum_on);
  for (int i = 1; i < len(state); i++) {
    int aux = 0;
    int cat = 0;
    if (i % 2 == 1) {
      cat = state[i] - state[i - 1] - 1;
      cat += sum_on[i - 1];
      cat += sum_off[i];
    } else {
      cat = state[i] - (state[i - 1] + 1);
      cat += sum_on[i - 1];
      cat += sum_off[i];
    }
    ans = max(ans, cat);
  }
  cout << ans << '\n';
  return 0;
}
