//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=448

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int A[30000];
	int ct;
	cin >> ct;
	for(int q = 0; q < ct; q++){
		int stops;
		cin >> stops;
		A[0] = 0;
		int a = 0, b = 0, c = 0;
		int sum = 0, ans = 0;
		for(int i = 1; i < stops; i++){
			scanf("%d", &A[i]);
		}
		for(int i = 1; i < stops; i++){
			sum += A[i];
			if(sum > ans || (ans == sum && (i - a > b - c))){
				ans = sum;
				b = i;
				c = a;
			}
			if(sum < 0){
				a = i;
				sum = 0;
			}
		}
		if(ans > 0){
			printf("The nicest part of route %d is between stops %d and %d\n", q+1, c+1, b+1);
		}else{
			printf("Route %d has no nicest part\n", q+1);
		}
	}
	return 0;
}

