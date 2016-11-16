#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	int n, a;
	while(scanf("%d %d", &n, &a)){
		if(n == 0 && a == 0) break;
		int vet[n];
		//memset(vet, 0, sizeof vet);
		for(int i = 0; i < n; i++){
			scanf("%d", &vet[i]);			
		}
		sort(vet, vet+n);		
	}
	return 0;
}

