#include <set>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

#define len(x) ((int)(x).size())
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 110;

int main(){
  int n;
  scanf("%d", &n);
  multiset<string> ms;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    ms.insert(s);
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    if(ms.count(s)){
      ms.erase(ms.find(s));
    }else{
      ans++;
    }
  }
  printf("%d\n", ans);
	
  return 0;
}
