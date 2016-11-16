#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int mem[10][10][10];
int n, a, b;
vi y;

void split(int num){
  y.clear();
  while (num){
    y.push_back(num % 10);
    num /= 10;
  }
  reverse(y.begin(), y.end());
}

long long pd(int i, int qtd, int leftmost_lo, int leftmost_hi, int x){
  if (i == n){
    if (leftmost_lo <= leftmost_hi) return qtd;
    else return 0;
  }
  
  if (mem[i][leftmost_lo][leftmost_hi] != -1){
    //printf("vou retornar %d\n", mem[i][leftmost_lo][leftmost_hi]);
    return mem[i][leftmost_lo][leftmost_hi];
  }

  int result = 0;
  int start = (x == 0 && i == 0) ? 1 : 0;

  for (int d = start; d <= 9; d++) {
    int lo = leftmost_lo;
    int hi = leftmost_hi;
    if (d < y[i] && i < lo) lo = i;
    if (d > y[i] && i < hi) hi = i;
    
    if (d == x) {
      result += pd(i+1, qtd + 1, lo, hi, x);
    }else{
      result += pd(i+1, qtd, lo, hi, x);
    }
  }

  return mem[i][leftmost_lo][leftmost_hi] = result;
}

int main(){
  while (scanf("%d %d",&a,&b) && a) {
    long long ans[10];
    memset(ans, 0, sizeof ans);
    split(a-1);
    n = (int) y.size();    
    for (int i = 0; i <= 9; i++) {                  
      memset(mem, -1, sizeof mem);
      long long qtd1 = pd(0, 0, n, n, i);      
      ans[i] = qtd1;
      //printf("primeiro com i = %d deu %lld\n", i, ans[i]);
    }

    split(b);
    n = (int) y.size();    
    for(int i=0; i <= 9; i++){
      memset(mem, -1, sizeof mem);
      long long qtd2 = pd(0, 0, n, n, i);
      //printf("segundo com i = %d deu %lld\n", i, qtd2);
      ans[i] = qtd2 - ans[i];
    }
    for(int i = 0; i <= 9; i++){
      printf("%lld ", ans[i]);
    }
    puts("");
  }
  return 0;
}
