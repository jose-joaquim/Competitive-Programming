#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int n; 

int change(int i, ii &o, ii &p){
  //printf("to em %d, (%d, %d) || (%d, %d)\n", i, o.first, o.second, p.first, p.second);
  if(i > 0){
    if(o.second == p.first){
      //puts("oi");
      return 0;
    }
    if(o.second == p.second){
      //puts("asd");
      swap(p.first, p.second);
      return 1;
    }
  }else{
    if(o.second == p.first){
      //puts("kkk");
      return 0;
    }
    if(o.second == p.second){
      //puts("qqq");
      swap(p.first, p.second);
      return 1;
    }
    if(o.first == p.second){
      //puts("mama");
      swap(o.first, o.second);
      swap(p.first, p.second);
      return 2;
    }
  }

  //puts("po");
  return -1;
}

int solve(vector<ii> lr){
  int ans1 = 0, ans2 = 0;
  for(int i = 0; i < n-1; i++){
    int a = change(i, lr[i], lr[i+1]);
    if(a != -1){
      ans1 += a;
    }else{
      ans1 = 1000000000;
      break;
    }
  }
  //puts("\n\n");
  swap(lr[0].first, lr[0].second);
  ans2 += 1;
  for(int i = 0; i < n-1; i++){
    int a = change(i, lr[i], lr[i+1]);
    if(a != -1){
      ans2 += a;
    }else{
      ans2 = 1000000000;
      break;
    }
  }
  //printf("ans1 eh %d, ans2 eh %d\n", ans1, ans2);
  return min(ans1, ans2);
}

int main(){
 scanf("%d", &n);
  vector<ii> vet;
  for(int i = 0; i < n; i++){
    int u, v; cin >> u >> v;
    vet.push_back(ii(u, v));
  }
  int ans = solve(vet);
  if(ans == 1000000000){
    puts("-1");
  }else printf("%d\n", ans);
  return 0;
}
