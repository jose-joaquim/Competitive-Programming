#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)
#define INF -100000;

int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}

//int A[] = {-7, 10, 9, 2, 3, 8, 8, 1}; //-7 1 2 3 8 8 9 10 
//int A[] = {2, 6, 3, 4, 1, 2, 9, 5, 8};
int A[] = {2, 5, 3};
//0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15

int upper_bound(int x, int size){
	int ini = 0; int fim = size;
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

int main(int argc, char **argv)
{
	
	int size = sizeof(A)/sizeof(A[0]);
	int length[size]/*, cpy[size]*/, L[size];
	int LIS = 0, i;
	
	for(i = 0; i < size; i++) length[i] = INF;
	//qsort(cpy, size, sizeof(int), cmp);
	
	L[0] = A[0];
	length[0] = 1;
	int cont = 0;
	for(i = 1; i < size; i++){
		if(A[i] > L[i-1]){
			L[i] = A[i];
			length[i] = length[i-1] + 1;
			LIS = max(LIS, length[i]);
			//printf("extendi a lista com %d\n", A[i]);
			cont++;
		}else if(A[i] < L[i-1]){
			//printf("vou procurar o upper_bound %d na lista\nO tamanho de L no momento eh %d\n", A[i], LIS);
			
			int x = upper_bound(A[i], LIS);
			/*printf("achei na posicao %d\n", x);
			system("pause");
			printf("substitui %d por %d\n", L[x], A[i]);*/
			L[x] = A[i];
		}
	}
	printf("%d\n", cont);
	/*for(i = 0; i < size; i++){
		length[i] = 1;
		for(j = 0; j < i; j++){
			if(A[j] < A[i] && length[j] + 1 > length[i]){
				length[i] = length[j] + 1;
			}
			LIS = max(length[i], LIS);			
		}
	}
	int maxI = LIS;
	for(i = size; i >= 0; i--){
		if(length[i] == maxI){
			printf("%d\n", A[i]);
			maxI--;
		}		
	}
	printf("%d\n", LIS);*/
	return 0;
}

