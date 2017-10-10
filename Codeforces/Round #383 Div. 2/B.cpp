#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int n, x;

bool binary(int q){
  int lo = 0, hi = n-1, mid;
  while(lo <= hi){
    mid = (lo + hi)/2;
    if(arr[mid] == q) return true;
    if(q < arr[mid]){
      hi = mid-1;
    }else lo = mid+1;
  }
  return false;
}

int solve(){
  int qtd = 0, i = 0;
  sort(arr.begin(), arr.end());
  for(int i = 0; i < n; i++){
    int oq = arr[i] xor x;
    if(binary_search(arr.begin(), arr.end(), oq)){
      auto p = equal_range(arr.begin(), arr.end(), oq);
      //i += p.second - p.first;
      qtd += p.second - p.first;
    }//else i++;
  }
  return qtd;
}

int main(){
  cin >> n >> x;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    arr.push_back(x);
  }
  int ans = solve();
  if(x == 0) ans -= n;
  printf("%d\n", ans/2);
  return 0;
}
