#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

typedef long long ll;

using namespace std;

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int q = 1; q <= ct; q++){
		int T;
		cin >> T;
		ll ans = T;
		for(int i = 2; i * i <= T; i++){
			int cont = 0;
			while(T % i == 0){
				//printf("t eh %d\n", T);
				cont++; T /= i;
			}
			if(cont % 2 == 1) ans *= i;
		}
		if(T > 1) ans *= T;
		printf("Caso #%d: %lld\n", q, ans);
	}
	return 0;
}
