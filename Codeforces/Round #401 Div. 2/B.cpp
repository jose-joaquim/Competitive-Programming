#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

char s[1002], m[1002];
int x;
ii getFlick(){
  int ret = 0, ret2 = 0;
  bool go = false;
  for(int j = 0; j < x; j++){
    go = false;
    for(int i = 0; i < x; i++){
      if(m[j] > s[i]){
        go = true;
      }
    }
    if(go) ret++;
    if(!go) ret2++;
  }
  return ii(ret2, ret);
}

int getMin(){
  int ret = 0;
  for(int i = 0; i < x; i++){
    bool go = false;
    if(m[i] == s[i]) go = true;
    else{
      for(int j = 0; j < x; j++){
        if(m[i] >= s[j]){
          go = true;
        }
      }
    }
    if(!go) ret++;
  }
  return ret;
}

int main(){
  cin >> x;
  scanf("%s", s);
  scanf("%s", m);
  ii ans = getFlick();
  cout << ans.first << endl << ans.second << endl;
  return 0;
}
