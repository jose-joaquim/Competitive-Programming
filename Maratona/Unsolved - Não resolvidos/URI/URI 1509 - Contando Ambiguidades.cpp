#include <bits/stdc++.h>

using namespace std;

map<string, bool> D;
vector<string> pp;
vector<string> words;

int n, u;

int main(){
  while(scanf("%d", &n) != EOF){
    words.clear(); D.clear();
    int cont = 0;
    for(int i = 0; i < n; i++){
      string x; cin >> x;
      D[x] = bool;
    }
    scanf("%d", &u);
    for(int i = 0; i < u; i++){
      string x; cin >> x;
      words.push_back(x);
    }
  }
  return 0;
}
