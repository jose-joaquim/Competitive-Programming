#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

using namespace std;

const int N = int(3e5) + 7;

int n;
string s[N];
char buf[N];
int cnt[N];

int getBalance(string &s){
  int bal = 0;
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == '(')
      ++bal;
    else
      --bal;
		
    if(bal < 0) {
      printf("entrei com %s\n", s.c_str());
      return -1;
    }
  }
	
  return bal;
}

string rev(string &s){
  string revs = s;
  reverse(revs.begin(), revs.end());
  for(int i = 0; i < revs.size(); ++i)
    if(revs[i] == '(')
      revs[i] = ')';
    else
      revs[i] = '(';
		
  return revs;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%s", buf);
    s[i] = buf;
  }

  for(int i = 0; i < n; ++i){
    int bal = getBalance(s[i]);
    if(bal != -1)
      ++cnt[bal];
  }
	
  long long res = 0;	
  for(int i = 0; i < n; ++i){
    s[i] = rev(s[i]);
    printf("%s ao contrario\n", s[i].c_str());
    int bal = getBalance(s[i]);
    if(bal != -1) {
      cout << bal << endl;
      res += cnt[bal];
    }
  }
  
  cout << res << '\n';
  return 0;
}
