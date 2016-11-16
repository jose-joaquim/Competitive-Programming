#include <stdio.h>

int main(int argc, char **argv)
{
	int x = 0;
	//x |= (1 << 2);
	x |= (1 << 3);

  
	printf("%d\n", x);// (x >> 3) & 1);
	return 0;
}

