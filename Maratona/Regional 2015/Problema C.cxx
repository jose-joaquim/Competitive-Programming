#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	int a, b;
	cin >> a >> b;
	if(a >= b){
		printf("%d\n", a);
	}else{
		printf("%d\n", b);
	}
	return 0;
}

