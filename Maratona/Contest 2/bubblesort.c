#include <stdio.h>

int main(int argc, char **argv)
{
	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, j, temp;
	for(i = 0; i<9; i++) //i < n
	puts("oi");
		for(j = 0; j<8; j++) // i < n-1
			if(vet[j] > vet[j+1]){
				temp = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = temp;
			}
	for(i = 0; i<9; i++)
		printf("%d ", vet[i]);
		
		puts("");
	return 0;
}

