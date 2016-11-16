#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int memo[100000 + 10];
int m, n, t;

/*int dp(int i){
	if(memo[i] != -1) return memo[i];
	
	if(i - n < 0 && i - m < 0) return memo[i] = i;
	
	return memo[i];
}*/

int main(int argc, char **argv)
{
	while(scanf("%d %d %d", &m, &n, &t) != EOF){
		memset(memo, 0, sizeof memo);
		
		//if(m > n) swap(m, n);
		
		memo[m] = 1;
		memo[n] = 1;
		
		for(int i = 0; i <= t; i++){
			if(memo[i]){
				if(i + m <= t) memo[i + m] = max(memo[i + m], memo[i] + 1);
				if(i + n <= t) memo[i + n] = max(memo[i + n], memo[i] + 1);
			}
		}
		
		if(memo[t]){
			printf("%d\n", memo[t]);
		}else{
			for(int i = t-1; i >= 0; i--){
				if(memo[i] > 0){
					printf("%d %d\n", memo[i], t - i);
					//printf("asldn %d\n", memo[t - i]);
					goto NEXT;
				}
			}
			printf("0 %d\n", t);
		}
		NEXT:
			continue;
	}
	return 0;
}

