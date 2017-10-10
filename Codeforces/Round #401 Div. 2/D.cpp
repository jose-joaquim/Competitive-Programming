#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int n;
vector<string> hashs;

int main(){
  scanf("%d", &n);
  hashs.resize(n);
  for(auto &x : hashs){
    cin >> x;
  }
  return 0;
}
