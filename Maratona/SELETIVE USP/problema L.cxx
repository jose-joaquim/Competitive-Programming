#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

//double memo[1002];


int main(int argc, char **argv)
{
	int dias, j = 0;
	scanf("%d", &dias);
	for(j = 1; ; j++){
		double p = pow((1.0/dias), j);
		for(int i = dias+1-j; i < dias+1; i++){
			p *= i;
		}
		if(1 - p >= 0.50) break;
	}
	printf("%d\n", j);
	return 0;
}

