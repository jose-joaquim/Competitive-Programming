#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

vector<int> A;

int binary(int x){
	int ini = 0, fim = (int) A.size()-1;
	int mid = 0;
	while(ini <= fim){
		mid = (ini + fim)/2;
		
		if(A[mid] == x) return mid;
		
		if(A[mid] > x){
			fim = mid - 1;
		}else{
			ini = mid + 1;
		}
	}
	return -1;
}
int main(int argc, char **argv)
{
	int ct;
	while(scanf("%d", &ct) != EOF){
		A.clear();
		int k, diff = 1000000, price, i = 0, j = 0, a = 0, b = 0;
		for(int i = 0; i < ct; i++){
			scanf("%d", &k);
			A.push_back(k);
		}
		sort(A.begin(), A.end());
		scanf("%d", &price);
		int size = (int) A.size();
		for(i  = 0; i < size; i++){
			if((j = binary(price - A[i])) != -1){
				if(j != i && abs(i - j) < diff){
					a = A[i];
					b = A[j];
					diff = abs(i - j);
				}
			}
		}
		if(a > b){
			int temp = a;
			a = b;
			b = temp;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
	}
	return 0;
}

