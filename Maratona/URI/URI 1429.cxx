#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
	int fat[7];
	fat[0] = 1;
	fat[1] = 1;
	for(int i = 2; i < 7; i++){
		fat[i] = i*fat[i-1];
	}
	char num[10];
	while(scanf("%s", num) && num[0] != '0'){
		int sz = strlen(num);
		int ans = 0;
		for(int i = 0; num[i] != '\0'; i++){
			ans += fat[sz]*(num[i] - '0');
			sz--;
		}
		printf("%d\n", ans);
	}
	return 0;
}

