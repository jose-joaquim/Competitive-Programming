#include <stdio.h>

void bubble(long long *vector, int x){
	int i, j;
	long long temp;
	for(i = 0; i<x; i++) //i < n
		for(j = 0; j<x-1; j++) // i < n-1
			if(vector[j] > vector[j+1]){
				temp = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = temp;
			}
}	
	

