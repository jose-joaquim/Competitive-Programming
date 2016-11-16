#include <stdio.h>

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	if(a == b && a == c && a == d){
		puts("S");
	}else if(a <= b && a <= c && a <= d){//se a for o menor dos lados, desconsidera-lo
			if((b + c) > d && (b + d) > c && (c + d) > b){
				puts("S");
			}else puts ("N");
	}else if(b <= a && b <= c && b <= d){//se b for o menor dos lados, desconsidera-lo
		if((a + c) > d && (a + d) > c && (d + c) > a){
			puts("S");
		}else puts ("N");
	}else if(c <= a && c <= b && c <= d){//se c for o menor dos lados, desconsidera-lo
		if((a + b) > d && (a + d) > c && (d + c) > a){
			puts("S");
		}else puts ("N");
	}else if(d <= a && d <= b && d <= c){//se d for o menor dos lados, desconsidera-lo
		if((a + b) > c && (a + c) > b && (b + c) > a){
			puts("S");
		}else puts ("N");
	}
	
	return 0;
}

