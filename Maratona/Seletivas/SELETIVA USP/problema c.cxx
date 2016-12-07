#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>

#define EPS 1e-9

using namespace std;

int main(int argc, char **argv)
{
	int h, w;
	scanf("%d %d", &h, &w);
	double vet[2][h];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < h; j++){
			scanf("%lf", &vet[i][j]);
		}
	}
	double lo = 0.0, hi = w, mid = 0.0, ans = 0.0;
	bool cane = false;
	while(fabs(hi-lo) > EPS){
		mid = (lo + hi) / 2.0;
		cane = false;
		for(int j = 0; j < h; j++){
			double a, b;
			a = (double)vet[0][j];
			b = (double)vet[1][j];
			a += mid;
			b += mid;
			if((int)(a + b) >= w){ cane = true; break; }
		}
		if(cane){
			ans = mid;
			hi = mid;
		}else{
			lo = mid;
		}
	}
	printf("%.1lf\n", ans);
	return 0;
}

