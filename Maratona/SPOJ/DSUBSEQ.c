#include <stdio.h>
#include <string.h>


typedef long long ll;

int T;
ll V[100005];
char S[100005];

ll const MOD = 1000000007;

ll solve(){
  int jaVi[26];
  memset(jaVi, -1, sizeof jaVi);
  memset(V, 0, sizeof V);
  int size = (int) strlen(S);

  V[0] = 1;
  //jaVi[S[0] - 'A'] = 1;
  for(int i = 1; i <= size; i++){
    V[i] = V[i - 1]*2;

    if(V[i] >= MOD) V[i] -= MOD;

    if(jaVi[S[i - 1] - 'A'] != -1){
      //printf("A ultima vez que eu vi %c tinha %d\n", S[i-1], V[jaVi[S[i-1] - 'A']]);
      V[i] -= V[jaVi[S[i-1] - 'A']];
      if(V[i] < 0) V[i] += MOD;
    }

    jaVi[S[i-1] - 'A'] = i - 1;
  }

  return V[size];
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%s", S);
    printf("%lld\n", solve());
  }
  return 0;
}
