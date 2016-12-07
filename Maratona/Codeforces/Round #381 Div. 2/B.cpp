#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> flower;
vector<int> somas;


int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
	int n; cin >> n;
	flower.push_back(n);
  }
  for(int i = 0; i < m; i++){
	int l, r, sum = 0;
	scanf("%d %d", &l, &r);
	for(int j = l-1; j <= r-1; j++){
	  sum += flower[j];
	}
	somas.push_back(sum);
  }
  sort(somas.begin(), somas.end());
  int ans = 0;
  for(int i = somas.size() - 1; i >= 0; i--){
	if(somas[i] < 0) break;
	ans += somas[i];
  }
  if(ans < 0) printf("0\n");
  else printf("%d\n", ans);
  return 0;
}
