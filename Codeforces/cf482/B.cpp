#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


typedef vector<int> vi;
int n;
map<string, int> name;
map<int, string> id_;
int ans = 0, ans_i;
vector<int> points(4, 0);
string a, b, c;

int verify(string &a) {
  cout << a;
  vi letters(26, 0);
  for (auto x: a) {
    letters[x - 97]++;
  }
  int ret = -1;
  for (auto x : letters) {
    ret = max(ret, x);
  }
  cout << " " << ret << endl;
  return ret;
}

void bfs(int id, string ini) {
  queue<pair<int, string> > q;
  q.push(make_pair(1, ini));
  unordered_map<string, int> seen;
  while(!q.empty()) {
    pair<int, string> p = q.front();
    q.pop();
    string w = p.second;
    int t = p.first;
    points[id] = max(points[id], verify(w));
    //cout << t << endl;
    if (t == n) continue;
    for (int i = 0; i < (int) w.size(); i++) {
      string w1 = w, w2 = w;
      if (w[i] == 'z') {
        w1[i] = 'a';
        w2[i] = 'y';
      } else if (w[i] == 'a') {
        w1[i] = 'b';
        w2[i] = 'z';
      } else {
        w1[i]++;
        w2[i]--;
      }
      //cout << "asda " << w1 << endl;
      //cout << t + 1 << endl;
      if (seen.find(w1) == seen.end()) {
        q.push(make_pair(t + 1, w1));
        seen[w1] = true;
      }
      if (seen.find(w2) == seen.end()) {
        q.push(make_pair(t + 1, w2));
        seen[w2] = true;
      }
    }
  }
}

int main() {
  id_[1] = "Kuro";
  id_[2] = "Shiro";
  id_[3] = "Katie";
  cin >> n; n %= 26;
  cin >> a >> b >> c;
  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);
  transform(c.begin(), c.end(), c.begin(), ::tolower);
  bfs(1, a); bfs(2, b); bfs(3, c);
  int maxv = 0, minp = -1;
  for (int i = 1; i <= 3; i++) {
    //cout << points[i] << endl;
    if (points[i] > maxv) {
      maxv = points[i];
      minp = i;
    }
  }
  
  for (int i = 1; i <= 3; i++) {
    if (points[i] == maxv && i != minp) {
      puts("Drawn");
      return 0;
    }
  }

  cout << id_[minp] << endl;
  return 0;
}
