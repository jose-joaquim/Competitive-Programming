#include <iostream>

int main(int argc, char **argv)
{
		int n=0;
		while(scanf("%d",&n) && n){
			int sum = 0;
			for(int i=0; i < n; i++){
				int c, k;
				scanf("%d %d",&c,&k);
				k -= (k%2);
				sum += k/2;
				}
				printf("%d\n",sum/2);
			}
	return 0;
}

