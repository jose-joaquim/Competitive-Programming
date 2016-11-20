#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>

using namespace std;
/*
int matrix[105][12];*/
int v1, v2;
int t, d;

/*int dp(int tempo, int vetAtual){
	if(vetAtual < 0) return -100000000;
	
	if(tempo == t){
		if(vetAtual == v2){
			return distAtual;
		}else{
			return -1000000000;
		}
	}
	
	if(matrix[tempo][vetAtual] != -1){
		return matrix[tempo][vetAtual];
	}
	
	for(int i = -d; i <= d; i++){//i eh a aceleracao
		distAtual = max(distAtual, dp(tempo + 1, vetAtual + i));
	}
	
	return matrix[tempo][vetAtual] = distAtual;
}*/

int main(int argc, char **argv)
{
	//memset(matrix, -1, sizeof matrix);
	scanf("%d %d", &v1, &v2);
	scanf("%d %d", &t, &d);
	int ans = 0;
	for(int i = 0; i < t; i++){
		ans += min(v1 + d*i, v2 + d*(t-i-1));
	}
	printf("%d\n", ans);
	return 0;
}

