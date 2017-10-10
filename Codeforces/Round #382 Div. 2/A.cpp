#include <bits/stdc++.h>

using namespace std;

int n, k;
char goat[105];

bool par(int x){
  return !(x%2);
}

bool impar(int x){
  return x%2;
}

int main(){
  scanf("%d %d", &n, &k);
  int ini, fim;
  for(int i = 1; i <= n; i++){
    cin >> goat[i];
    //scanf("%c", &goat[i]);
    // printf("li %c\n", goat[i]);
    if(goat[i] == 'T'){
      fim = i;
    }else if(goat[i] == 'G'){
      ini = i;
    }
  }
  if(fim > ini){
    bool can = false;
    for(int i = ini; i <= n; i += k){
      if(goat[i] == '#'){
        break;
      }else if(goat[i] == 'T'){
        can = true;
        break;
      }
    }
    puts(can ? "YES" : "NO");
  }else if(ini > fim){
    bool can = false;
    for(int i = ini; i >= 1; i -= k){
      if(goat[i] == '#') break;
      if(goat[i] == 'T'){
        can = true;
        break;
      }
    }
    puts(can ? "YES" : "NO");
  }
  return 0;
}
