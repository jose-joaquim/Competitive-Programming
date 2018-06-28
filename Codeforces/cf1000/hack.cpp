#include <map>
#include <set>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using namespace std;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n;
  cin>>n;
  map<string,int>m1;
  map<string,int>m2;
  for (int i = 0; i < n ; ++i) {
    string x;
    cin>>x;
    m1[x]++;
  }
  for (int j = 0; j < n ; ++j) {
    string x;
    cin>>x;
    if(m1[x]>0)
      m1[x]--;
    else{
      m2[x]++;
    }
  }
  int res=0;
  map<string,int>::iterator i,j;
  if(m2.size()==1){
    i=m2.begin();
    int z=m2[i->first];
    while(z){
      int minn=5;
      string index;
      for ( j = m1.begin(); j !=m1.end() ; ++j) {
        if(j->second==0)
          continue;
        if(i->first.size()==j->first.size()){
          int m=0;
          int s=i->first.size();
          for (int k = 0; k < s ; ++k) {
            if(i->first[k]!=j->first[k]){
              m++;
            }
          }
          if(m<minn){
            minn=m;
            index=j->first;
          }
        }
      }
      res+=minn;
      m2[i->first]--;
      m1[index]--;

      z--;
    }
  }
  else {
    for (i = m2.begin(); i != m2.end(); ++i) {
      if (i->second == 0)
        continue;
      while (m2[i->first] > 0 ) {
        int minn = 5;
        string index;
        for (j = m1.begin(); j != m1.end(); ++j) {
          if (j->second == 0)
            continue;
          if (i->first.size() == j->first.size()) {
            int m = 0;
            int s = i->first.size();
            for (int k = 0; k < s; ++k) {
              if (i->first[k] != j->first[k]) {
                m++;
              }
            }
            if (m < minn) {
              minn = m;
              index = j->first;
            }
          }
        }
        res += minn;
        m2[i->first]--;
        m1[index]--;

      }

    }
  }
  cout<<res << endl;;
  return 0;
}
