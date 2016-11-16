#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

long long n, k;

int main(int argc, char **argv)
{
	scanf("%I64d %I64d", &n, &k);
	long long vet[n];
	for(long long i = 0; i < n; i++){
		scanf("%I64d", &vet[i]);
	}
	sort(vet, vet+n);
	long long vez = 0, money = 0;
	//qsort(vet, n, sizeof(int), cmp);
	bool go = true;
	
	for(long long i = 0; i < n; i++){
		for(long long j = i + 1; j < n; j++){
			money = vet[i] + vet[j];
			if(vez == k){
				go = false;
				break;
			}
			vez++;
			
		}
		if(!go) break;
	}
	printf("%I64d\n", money);
	return 0;
}

