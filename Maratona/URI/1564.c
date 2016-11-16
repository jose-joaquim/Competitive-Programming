#include <stdio.h>

int main(int argc, char **argv)
{
	int x;
	while(scanf("%d", &x) != EOF){
		if(x > 0){
			printf("vai ter duas!\n");
		}else printf("vai ter copa!\n");
	}
	return 0;
}

