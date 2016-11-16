#include <iostream>
#include <cstdio>

using namespace std;

int dest, ini;

int inverte(int x) {
    int inv = 0;
    while (x > 0) {
        inv = 10 * inv + x % 10;
        x /= 10;
    }
    return inv;
}

void goOn(int c, int num){
	if(num == dest){
		printf("passos %d\n", c);
	}else{
		int aux = inverte(num);
		goOn(c+1, aux);
		goOn(c+1, num+1);
	}
}

int main(int argc, char **argv)
{
	scanf("%d %d", &ini, &dest);
	goOn(0, ini);
	return 0;
}

