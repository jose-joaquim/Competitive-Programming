#include <stdio.h>

int expo(int x, int a){
	if(a == 0){
		return 1;
	}else{
		return x*expo(x, a-1);
	}
}

int main(int argc, char **argv)
{
	int qtd, c, d, i;
	scanf("%d", &qtd);
	for(i = 0; i<qtd; i++){
		scanf("%d %d", &c, &d);
		if(c == 0 && d == 0){
			puts("0");
		}else printf("%d\n", (expo(26, c))*expo(10, d));
	}
	return 0;
}

