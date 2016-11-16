#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int fatorial(int n){
	int fat = 1;
	for(fat = 1; n > 1; n = n - 1)
		fat = fat * n;
	return fat;
}

int cont = 0;
	int first, last;
	bool e;
	int n, m;
	int matriz[20][3];
	int vetor[8];

bool check(){
	for(int i = 0; i < m; i++){
		first = last = 0;
		for(int j = 0; j < n; j++){
			if(vetor[j] == matriz[i][0]){
				first = j;
			}
			if(vetor[j] == matriz[i][1]){
				last = j;
			}
		}
		int diff = (int) abs(first - last);
		if(matriz[i][2] > 0){
			if(diff > abs(matriz[i][2])){
				return false;
			}
		}
		if(matriz[i][2] < 0){
			if(diff < abs(matriz[i][2])){
				return false;
			}
		}			
	}
	return true;
}
int main(int argc, char **argv)
{		
	while(cin >> n >> m){		
		if(n == 0 && m == 0) break;
		e = true;
		cont = 0; 
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &matriz[i][0], &matriz[i][1], &matriz[i][2]);	
		}
		for(int j = 0; j < n; j++){
				vetor[j] = j;
		}
		do{
			if(check()){
				cont++;
			}			
		}while(next_permutation(vetor, vetor+n));
		printf("%d\n", cont);
	}
	return 0;
}

