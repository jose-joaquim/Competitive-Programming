#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

unsigned long long memo[1000][1000];
unsigned long long count;

unsigned long long trib(int n, int back){
	if(n <= 1) return 1;
	if(memo[n][back] != 0) return memo[n][back];
	memo[n][back] = 1;
	for(int i = 1; i <= back; i++){
		memo[n][back] += trib(n - i, back);
	}
	return memo[n][back];
}

int main(int argc, char **argv)
{
	
	int i, j, k = 0;
	memset(memo, 0, sizeof memo);
	while(scanf("%d %d", &i, &j) && (i < 61)){
		count = 0;
		printf("Case %d: %llu\n", ++k, trib(i, j));		
	}
	return 0;
}

