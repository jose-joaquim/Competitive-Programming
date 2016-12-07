#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

int n, n1, n2;
int we[100005];

int main(){
  scanf("%d %d %d", &n, &n1, &n2);
  for(int i = 0; i < n; i++){
    scanf("%d", &we[i]);
  }
  sort(we, we + n);
  double ans1 = 0.0, med1 = 0.0, med2 = 0.0;
  if(n1 > n2) swap(n1, n2);
  //n1 sempre sera a  cidade com menor integrantes
  for(int i = n - n1; i < n; i++){
    //printf("peguei %d\n", we[i]);
    med1 += (double) we[i];
  }
  med1 = med1/n1;
  //printf("med1 foi %lf\n", med1);
  for(int i = n - n1 - n2; i < n - n1; i++){
    //printf("peguei %d\n", we[i]);
    med2 += (double) we[i];
  }
  med2 = med2/n2;
  //printf("med2 foi %lf\n", med2);
  printf("%lf\n", med1 + med2);
  return 0;
}
