#include <stdio.h>

int main(int argc, char **argv)
{
	int x, i, hit = 0, j;
	int resp[5];
	scanf("%d", &x);
	for(i = 0; i < 5; i++){
		scanf("%d", &j);
		resp[i] = j;
	}
	for(i=0; i< 5; i++){
		if(resp[i] == x){
			hit++;
		}
	}
	printf("%d\n", hit);
	return 0;
}

