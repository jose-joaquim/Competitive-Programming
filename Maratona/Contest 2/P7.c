#include <stdio.h>

int main()
{
	int x, y, z;
	while((scanf("%d %d %d", &x, &y, &z)) != EOF){
		if(x != y && x != z){
			printf("A\n");
		}else if(y != x && y != z){
			printf("B\n");
		}else if(z != x && z != y){
			printf("C\n");
		}
		if(x == y && x == z){
			printf("*\n");
		}		
	}
	return 0;
}

