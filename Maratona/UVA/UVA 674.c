#include <stdio.h>

int coins[] = {50, 20, 10, 5, 1};

#define min(a, b) ((a < b) ? a : b)
#define INF 1000000000

int ob;
int memo[7500];

void dp(){
	int i, j;
	memo[0] = 1;
	for(i = 0; i < 5; i++){
		for(j = coins[i]; j < 7500; j++){
			memo[j] += memo[j - coins[i]];
		}
	}
}

int main(int argc, char **argv)
{
	int ct;
	dp();
	while(scanf("%d", &ct) != EOF){
		printf("%d\n", memo[ct]);
	}
	return 0;
}

