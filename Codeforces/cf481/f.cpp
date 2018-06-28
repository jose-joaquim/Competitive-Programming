#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, k;
vector<pair<int, int> > skills;
vector<pair<int, int> > quarrels;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
  return a.second < b.second;
}

inline void printvector(vector<int> &a) {
  for (int i = 0; i < (int) a.size(); i++) {
    printf("%d ", a[i]);
  } puts("");
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> k;
  skills.resize(n);

  for (int i = 0; i < n; i++) {
    int u; cin >> u;
    skills[i] = {u, i};
  }

  sort(skills.begin(), skills.end());
  
  for (int i = 0; i < k; i++) {
    int u, v; cin >> u >> v;
    quarrels.push_back({u, v});
  }

  vector<int> skills_idx(n);
  
  for (int i = 0; i < n; i++) {
    //printf("%d %d\n", skills[i].first, skills[i].second);
    skills_idx[i] = skills[i].first;
  } //cout << '\n';
  
  vector<int> ans(n, 0);
  
  int q = 0;
  while (q < n) {
    int value = skills_idx[q];
    int low = lower_bound(skills_idx.begin(), skills_idx.end(), value) - skills_idx.begin();
    int upper = upper_bound(skills_idx.begin(), skills_idx.end(), value) - skills_idx.begin();
    //printf("(q %d) %d %d\n", q, low, upper);
    for ( ; q < upper; q++) {
      ans[q] = max(low, 0);
    }
  } //puts("");

  //printvector(ans);

  vector<int> aux(n);
  for (int i = 0; i < n; i++) {
    aux[skills[i].second] = ans[i];
  }

  //printvector(aux);

  sort(skills.begin(), skills.end(), cmp);

  /*for (int i = 0; i < n; i++) {
    printf("%d %d\n", skills[i].first, skills[i].second);
    skills_idx[i] = skills[i].first;
  } cout << '\n';*/

    
  for (int i = 0; i < k; i++) {
    int u = quarrels[i].first, v = quarrels[i].second;
    u--, v--;
    //printf("  %d (hab %d) vs %d (hab %d) \n", skills[u].second, skills[u].first, skills[v].second, skills[v].first);
    if (skills[u].first > skills[v].first) {
      //printf("hab %d > hab %d\n", skills[u].first, skills[v].first);
      aux[u] -= 1;
    } else if (skills[v].first > skills[u].first) {
      //printf("hab %d > hab %d\n", skills[v].first, skills[u].first);
      aux[v] -= 1;
    }
  }

  printvector(aux);
  return 0;
}
