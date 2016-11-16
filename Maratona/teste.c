#include <stdio.h>

int A[] = {1, 2, 9, 15, 20, 21, 23, 29};

int binary(int x){
	int ini = 0, fim = 7;
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
	printf("%d\n", binary(1));
	return 0;
}

