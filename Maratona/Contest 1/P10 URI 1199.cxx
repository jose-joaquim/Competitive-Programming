#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	char c[15];
	int k;
	while(gets(c) && ((k = atoi(c) != -1))){
		fflush(stdin);
		if(k == -1) break;
		if(c[0] == '0' && c[1] == 'x'){
			printf("%d\n", (int)strtol(c, NULL, 16));
		}else{
			printf("0x%X\n", (int)strtol(c, NULL, 10));
		}
	}	
	return 0;
}

