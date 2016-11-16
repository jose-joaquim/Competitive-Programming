#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	int a, b, c, d;
	//int quebra = 0;
	while(scanf("%d %d %d %d",&a, &b, &c, &d) && (a || b || c || d)){
		/*if(!quebra){
			quebra = 1;
		}else printf("\n");*/
		if(a == c && b == d){
			printf("0\n");
			continue;
		}
		if(abs(a - c) == abs(b - d)){
			printf("1\n");
			continue;
		}
		if(a == c){
			printf("1\n");
			continue;
		}
		if(b == d){
			printf("1\n");
			continue;
		}
		printf("2\n");
	}
	return 0;
}

