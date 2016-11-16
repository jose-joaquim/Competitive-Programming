#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vet;
int sz; 

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }

int recursao(int q){
	if(q == 0){
		return gcd(vet[0], 0);
	}else{
		return gcd(vet[q], recursao(q-1));
	}
}

int main(int argc, char **argv)
{
	//printf("%d\n", gcd(1, 11));
	int n;
	while(scanf("%d", &n) && n){
		int k;
		vet.clear();
		sz = 0;
		while(scanf("%d", &k) && k){
			vet.push_back(k);
			sz++;
		}
		for(int i = 0; i < sz; i++){
			vet[i] -= n;
		}
		sz--;
		printf("%d\n", (int)fabs(recursao(sz)));
	}
	return 0;
}

