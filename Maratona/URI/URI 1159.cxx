#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	int ct;
	while(scanf("%d", &ct) && ct){
		int aux = 0, num = ct, ans = 0;
		while(aux < 5){
			if(!(num%2)){
				ans += num;
				aux++;
			}
			num++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

