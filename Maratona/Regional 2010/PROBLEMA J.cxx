#include <iostream>
#include <cstdio>

int main(int argc, char **argv)
{
	int n;
	while(scanf("%d", &n) && n){
		for(int q = 0; q < n; q++){
			//int vet[4];
			int u;
			int ans = 0, pos = 0;
			for(int i = 1; i <= 5; i++){
				scanf("%d", &u);
				if(u <= 127){
					ans++;
					pos = i;
				}
			}
			if(ans > 1 || ans == 0) puts("*");
			else{
				switch(pos){
					case 1: puts("A"); break;
					case 2: puts("B"); break;
					case 3: puts("C"); break;
					case 4: puts("D"); break;
					case 5: puts("E"); break;
				}
			}
		}
	}
	return 0;
}

