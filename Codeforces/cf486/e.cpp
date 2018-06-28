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
unordered_set<string> seen;

bool divisible(const string &nova) {
  if (nova.size() < 2) {
    return false;
  } else {
    int sz = (int) nova.size();
    return (nova[sz - 1] == '0' && nova[sz - 2] == '0')
      || (nova[sz - 1] == '5' && nova[sz - 2] == '2')
      || (nova[sz - 1] == '0' && nova[sz - 2] == '5')
      || (nova[sz - 1] == '5' && nova[sz - 2] == '7');      
  }
}

long long bfs() {
  queue<sip> q;
  q.push(sip(number, 0));
  seen.insert(number);

  while(!q.empty()) {
    //cout << q.front().first << endl;
    string u = q.front().first;
    long long moves = q.front().second;
    q.pop();

    if (divisible(u))
      return moves;
    
    for (int i = 1; i < (int) u.size(); i++) {
      string aux = u;
      swap(aux[i], aux[i-1]);

      if (aux[0] == '0')
        continue;
      /*int j = 0;
      while(aux[j] == '0') j++;      
      string nova = aux.substr(j, aux.size());*/
      
      if (seen.find(aux) == seen.end()) {
        seen.insert(aux);
        q.push(sip(aux, moves + 1LL));
      }
    }
  }
  
  return -1;
}

int main() {
#ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#endif
  cin >> number;
  cout << bfs() << '\n';
  
  return 0;
}
