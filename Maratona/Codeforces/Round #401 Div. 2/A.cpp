#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int n, x; cin >> n >> x;
  n %= 6;
  while(n != 0){
    if(n % 2 == 0){
      //se estou em uma jogada par
      if(x == 2){
        x = 1;
      }else if(x == 1){
        x = 2;
      }
    }else{
      if(x == 0){
        x = 1;
      }else if(x == 1){
        x = 0;
      }
    }
    n--;
  }
  cout << x << endl;
  return 0;
}
