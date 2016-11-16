#include <stdio.h>

int coins[] = {1, 5, 10, 25, 50};
long long memo[30000 + 10];

void dp(){
	int i, j;
	memo[0] = 1;
	for(i = 0; i < 5; i++){
		for(j = coins[i]; j < 30000 + 10; j++){
			memo[j] += memo[j - coins[i]];
		}
	}
}

int main(int argc, char **argv)
{
	long long ct;
	dp();
	while(scanf("%lld", &ct) != EOF){
		printf(memo[ct] == 1? "There is only %lld way to produce %d cents change.\n" :
            "There are %lld ways to produce %d cents change.\n", memo[ct], ct);
	}
	return 0;
}

