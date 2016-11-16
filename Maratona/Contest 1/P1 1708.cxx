#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF){
		int dy = 0, dx = 0;
		
		int volta = 1;
		while(true){
			if((dy - dx) >= x) break;
			dx += x;
			dy += y;
			volta++;
		}
		
		printf("%d\n", volta);
	}
	return 0;
}

