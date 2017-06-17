//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2420
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n;
int ida[100001], volta[100001], vt[100001];

int main(){
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++)
    scanf("%d", &vt[i]);

  ida[0] = vt[0];
  for(int i = 1; i < n; i++)
    ida[i] = ida[i - 1] + vt[i];

  volta[n - 1] = vt[n - 1];
  for(int i = n - 2; i >= 0; i--)
    volta[i] = volta[i + 1] + vt[i];

  int ans = 0;
  while(ida[ans] != volta[ans + 1] && ans < n) ans++;

  printf("%d\n", ans+1);
  return 0;
}
