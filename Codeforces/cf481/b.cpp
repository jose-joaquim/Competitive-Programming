#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


int wrong(string &a) {
  int cnt = (a[0] == 'x');
  for (int i = 1; i < (int) a.size(); i++) {
    if (a[i] == 'x') {
      cnt++;
    } else if (a[i] != 'x') {
      cnt = 0;
    }

    if (cnt == 3) {
      //printf("x in %d\n", i);
      return i;
    }
  }
  return -1;
}

int main() {
  int n; cin >> n;
  string file; cin >> file;
  int ans = 0;
  vector<string> v;
  int k = 0;
  string aux = "";
  while(k < n) {
    bool go = false;
    while (file[k] == 'x') {
      go = true;
      aux += file[k];
      k++;
      go = true;
    }

    if (!go) {
      k++;
    } else {
      v.push_back(aux);
      aux = "";
    }
  }
  
  for (string a : v) {
    if (a.size() >= 3) {
      ans += ((int) a.size()) - 2;
    }
  }
  
  /*while(int pos = wrong(file) != -1) {
    ans += 1;
    string nova = "";
    for (int j = 0; j < pos; j++) {
      nova += file[j];
    }

    for (int j = pos + 1; j < (int) file.size(); j++) {
      nova += file[j];
    }

    file = nova;
    }*/
  cout << ans << '\n';
  return 0;
}
