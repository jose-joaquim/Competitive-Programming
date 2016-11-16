#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
float value;
long long memo[6000][6000];

long long ways(int type, int value){
	if(value == 0) return 1;
	if(value < 0) return 0;
	if(type == 11) return 0;
	if(memo[type][value] != -1) return memo[type][value];
	memo[type][value] = ways(type + 1, value) + ways(type, value - coins[type]);
	return memo[type][value];
}

int main(int argc, char **argv)
{
	char valor[50]; memset(memo, -1, sizeof memo);
	bool quebra = false;
	while(scanf("%s", valor) && strcmp(valor, "0.00")){
		if(!quebra) quebra = true;
		else printf("\n");
		char Q[50] = "", aaa[50] = "";
		strcat(Q, valor);
		char *pch;
		pch = strtok(valor, ".");
		while(pch != NULL){
			strcat(aaa, pch);
			pch = strtok(NULL, ".");
		}
		int value = atoi(aaa);
		printf("%6s%17lld", Q, ways(0, value));
	}
	return 0;
}
