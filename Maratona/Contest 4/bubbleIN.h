#include <stdio.h>

void bubble(int *vet, int n)
{
	int i, j, temp;
	for(i = 0; i<n; i++) //i < n
		for(j = 0; j<n-1; j++) // i < n-1
			if(vet[j] < vet[j+1]){
				temp = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = temp;
			}
}

