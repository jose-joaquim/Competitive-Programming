#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
	double a, b;
	while(scanf("%lf %lf", &a, &b) != EOF){
		printf("%.2lf\n", a/b);
	}
	return 0;
}

