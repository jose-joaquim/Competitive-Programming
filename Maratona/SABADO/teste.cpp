#include <bits/stdc++.h>

using namespace std;

int main(){
  int ct;
  scanf("%d", &ct);
  int pos_ans = -1;
  double ans = -1.0;
  for(int i = 0; i < ct; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    if(b*log(a) > ans){
      pos_ans = i;
      ans = b*log(a);
    }
  }
  printf("%d\n", pos_ans);
  return 0;
}
