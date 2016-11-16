#include <stdio.h>

int A[] = {-7, 1, 2, 3, 8, 8, 10, 15};

int upper_bound(int x){
	int ini = 0; int fim = sizeof(A)/sizeof(A[0]);
	int mid;
	while(ini <= fim){
		mid = (int) (ini+fim)/2;
		
		//if(A[mid] == x) return mid-1;
		
		if(A[mid] > x) fim = mid - 1;
		else ini = mid + 1;
		
	}
	//printf("mid eh %d\n", mid);
	return fim+1;
}

int lower_bound(int x/*, int *A, int size*/){
	//for(i = 0; i < size; i++) printf("%d ", A[i]);
	int ini = 0; int fim = 8;
	//printf("\n%d fim eh\n", fim);
	int mid;
	while(ini <= fim){
		mid = (int) (ini+fim)/2;
		
		if(A[mid] == x){
			fim = mid-1;
		}else if(A[mid] > x){
			fim = mid - 1;
		}else ini = mid + 1;
		
	}
	//printf("fim eh %d\n", fim);
	return fim;
}	

int main(int argc, char **argv)
{
	/*int A[] = {-7, 1, 2, 3, 8, 8, 10, 15};
	int size = sizeof(A)/sizeof(A[0]);*/
	printf("eh %d\n", A[upper_bound(1)]);
	printf("%d\n", A[lower_bound(10/*, A, size*/)]);
	return 0;
}

