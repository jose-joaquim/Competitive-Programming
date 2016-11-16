#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	int n;
	for(n = 6; n <= 200; n++){
		for(int i = 1; i < n; i++){
			for(int j = i; j < n; j++){
				for(int k = j; k < n; k++){
					if(n*n*n == i*i*i + j*j*j + k*k*k){		
						printf("Cube = %d, Triple = (%d,%d,%d)\n", n, i, j, k);
					}
				}
			}
		}
	}
	return 0;
}

