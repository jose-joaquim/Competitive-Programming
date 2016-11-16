#include <stdio.h>
#include <string.h>

#define max(a, b) ((a > b) ? a : b)
#define INF 1000000000;

int memo[305][55];
int qt[305];
int peso[55];
int pac;

int val(int id, int remW){
	if(remW < 0)			 return -INF;
	if(id == pac) 			 return 0;
	if(memo[id][remW] != -1) return memo[id][remW];
	if(peso[id] > remW) 	 return memo[id][remW] = val(id + 1, remW);
	return memo[id][remW] = max(val(id + 1, remW), qt[id] + val(id + 1, remW - peso[id]));
}

int main(int argc, char **argv)
{
	int ct, k;
	scanf("%d", &ct);
	for(k = 1; k <= ct; k++){
		int i = 0, j = 0;
		memset(memo, -1, sizeof memo);
		scanf("%d", &pac);
		for(j = 0; j < pac; j++){
			scanf("%d %d", &qt[j], &peso[j]);
		}
		int ans = val(0, 50);		
		int cap = 50;
		int items = 0;	
		while(i < pac-1){
			if(memo[i][cap] != memo[i+1][cap]){
				items += 1;
				cap -= peso[i];
				i += 1;
			}else{
				i += 1;
			}
		}
		if(memo[pac-1][cap] != 0){
			items += 1;
			cap -= peso[pac-1];
		}
		printf("%d brinquedos\n", ans);
		printf("Peso: %d kg\n", (50 - cap));
		printf("sobra(m) %d pacote(s)\n\n", pac - items);
	}
	return 0;
}

