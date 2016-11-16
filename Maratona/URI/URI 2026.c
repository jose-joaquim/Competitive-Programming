#include <stdio.h>
#include <string.h>

#define max(a, b) ((a >= b) ? a : b)

int P, W;
int memo[100][1001];
int E[105];
int weigth[100];

int val(int id, int remW){
	if(remW < 0) return -1000000000;
	if(id == P)	return 0;
	if(memo[id][remW] != -1) return memo[id][remW];
	if(weigth[id] > remW) return memo[id][remW] = val(id + 1, remW);
	return memo[id][remW] = max(val(id + 1, remW), E[id] + val(id + 1, remW - weigth[id]));
}

int main(int argc, char **argv)
{
	int ct, i, j;
	scanf("%d", &ct);
	for(i = 1; i <= ct; i++){
		memset(memo, -1, sizeof memo);
		scanf("%d %d", &P, &W);
		for(j = 0; j < P; j++){
			scanf("%d %d", &E[j], &weigth[j]);
		}
		printf("Galho %d:\n", i);
		printf("Numero total de enfeites: %d\n\n", val(0, W));		
	} 
	return 0;
}

