#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main(){
  int n, g;
  while(scanf("%d %d", &n, &g) != EOF){
    int x[n], y[n];
    vector<pair<int, int> > v;
    for(int i = 0; i < n; i++){
      scanf("%d %d", &x[i], &y[i]);
      v.push_back(make_pair(y[i] - x[i], i));
    }
    sort(v.begin(), v.end());
    int i = 0, ans = 0;
    while(i < n && g > 0){
      if(v[i].first >= 0 && v[i].first <= g){
        //printf("diferenca eh %d no jogo %d\n", v[i].first, v[i].second);
        int pos = v[i].second;
        x[pos] += v[i].first; //para empatar
        g -= v[i].first;
        if(g > 0){
          g--;
          x[pos]++; //para ganhar
        }
      }
      i++;
    }
    for(i = 0; i < n; i++){
      if(x[i] > y[i]) ans += 3;
      else if(x[i] == y[i]) ans += 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
