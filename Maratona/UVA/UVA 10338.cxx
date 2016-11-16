#include <bits/stdc++.h>

using namespace std;

const long long P = 1000 * 1000 * 1000 + 7;

typedef long long ll;

int n, den;
long long fat[1000 + 100 + 10 + 1];

long long mod_pow(long long base, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1)
      ans = (ans * base) % P;
    base = (base * base) % P;
    e >>= 1;
  }
  return ans;
}

ll fastexp(ll a,ll b){

  long long int x;

  if(b==0) return 1;
  if(b==1) return a;

  if(b%2==0){
    x = fastexp(a,b/2)%P;
    return (x*x)%P;
  }else{
    return (a*fastexp(a,b-1))%P;
  }

}


ll inv4(ll a){
  return fastexp(a,P-2);
}

int main(int argc, char **argv)
{
	fat[0] = 1;
	fat[1] = 1;
	for(int i = 2; i <= 22; i++) fat[i] = (fat[i-1]*i);
	char string[1005];
	int ct;
	scanf("%d", &ct);
	for(int k = 1; k <= ct; k++){
		scanf("%s", string);
		ll elemento[27], sz = strlen(string);
		for(int i = 0; i < 27; i++) elemento[i] = 0;
		for(int i = 0; i < sz; i++){
			elemento[string[i] - 'A']++;
		}
		ll numerador = fat[sz], denominador = 1;
		//printf("numerador eh %d (tem %d letras)\n", numerador, sz);
		for(int i = 0; i < 27; i++) denominador = (denominador * fat[elemento[i]]);
		printf("Data set %d: %lld\n", k, numerador/denominador);
	}
	return 0;
}
