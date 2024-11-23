#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

map<string, vector<string>> adj, adj_rev;
int n, c, t;
string a, b, z;

void dfs(set<string> &visited, const string &u) {
  visited.insert(u);

  for (auto &v : adj_rev[u]) {
    if (!visited.contains(v)) {
      dfs(visited, v);
    }
  }
}

string query(const string &a, const string &b) {
  set<string> v1, v2, intersect;
  dfs(v1, a);
  dfs(v2, b);

  std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                      std::inserter(intersect, intersect.begin()));
  return intersect.size() != v1.size() ? "verdadeiro" : "falso";
}

int main(int argc, char **argv) {
  cin >> n >> c >> t;
  for (int i = 0; i < c; ++i) {
    cin >> a >> b >> z;
    adj_rev[z].push_back(a);
    adj_rev[z].push_back(b);
  }

  for (int q = 0; q < t; ++q) {
    cin >> a >> b;
    cout << query(a, b) << endl;
  }
  return 0;
}
