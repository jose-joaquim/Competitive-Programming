#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;

int from[50000 + 5];
int to[50000 + 5];
int vet[50000 + 5];
int n;

int main(int argc, char **argv)
{
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d", &vet[i]);
		}
		to[1] = 1;
		for(int i = 1; i < n; i++){
			to[i+1] = min(to[i] + 1, vet[i+1]);
		}
		from[n] = 1;
		for(int i = n; i > 1; i--){
			from[i-1] = min(from[i] + 1, vet[i-1]);
		}
		/*puts("vetor from");
		for(int i = 1; i <= n; i++){
			printf("%d ", from[i]);
		}
		puts("");*/
		int ans = 1;
		for(int i = 1; i <= n; i++){
			ans = max(ans, min(to[i], from[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}

