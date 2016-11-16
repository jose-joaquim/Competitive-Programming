#include <stdio.h>
#include <string.h>

int memo[41];
int calls[41];

int fib(int x){
	if(x < 2){
		return memo[x] = 1;
	}
	if(memo[x] != -1){
		calls[x] = 1+ calls[x-1] + calls[x-2];
		return memo[x];
	}
	return memo[x] = fib(x-1) + fib(x-2);
}

int main(int argc, char **argv)
{
	int ct, i;
	memset(memo, -1, sizeof memo);
	memset(calls, -1, sizeof calls);
	memo[0] = 0;
	memo[1] = 1;
	calls[0] = 1;
	calls[1] = 1;
	scanf("%d", &ct);
	for(i = 0; i < 41; i++){
		fib(i);
	}
	for(i = 0; i < ct; i++){
		int k;
		scanf("%d", &k);
		printf("fib(%d) = %d calls = %d\n", k, calls[k]-1, memo[k-1]);
	}
	return 0;
}
/*
#include<stdio.h>
int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}
 
int main ()
{
  int n = 9;
  printf("%d", fib(n));
  getchar();
  return 0;
}*/

