#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long memo_cents[50000];

void dp_cents(){
	int i, j;
	memo_cents[0] = 1;
	for(i = 0; i < 11; i++){
		for(j = coins[i]; j < 30002; j++){
			memo_cents[j] += memo_cents[j - coins[i]];
		}
	}
}

int main(int argc, char **argv)
{
	dp_cents();
	float ct;
	while(scanf("%f", &ct) && (ct != 0.00)){
		unsigned x = (unsigned)((ct + 0.001) * 100);
		printf("%6.2f%17I64d\n", ct, memo_cents[x]);
	}
	return 0;
}



