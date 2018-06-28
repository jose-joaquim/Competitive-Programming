#include <map>
#include <set>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<string, string> ss;

int main() {
  ios::sync_with_stdio(0);
  int n; cin >> n;
  map<string, string> joias;
  joias["purple"] = "Power";
  joias["green"] = "Time";
  joias["blue"] = "Space";
  joias["orange"] = "Soul";
  joias["red"] = "Reality";
  joias["yellow"] = "Mind";
  for (int i = 0; i < n; i++) {
    string u; cin >> u;
    joias.erase(u);
  }

  cout << joias.size() << '\n';
  for (auto el : joias) {
    cout << el.second << '\n';
  }
  return 0;
}
