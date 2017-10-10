//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=565

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int sol = -1, somaMi[20], vet[20];
int N, Tracks, numPos = 0, sum;
int tmp = 0, maxSum;
vector<int> soma, ans; 


void backtrack(int c, int sum){	
	int i;	
	if(sum > maxSum){
		ans = soma;
		maxSum = sum;
	}
	for(i = c; i < Tracks; i++){
		if(sum + vet[i] <= N){
			sum += vet[i];
			soma.push_back(vet[i]);			
			backtrack(i+1, sum);
			sum -= vet[i];
			soma.pop_back();
		}
	}
}

int main(int argc, char **argv)
{
	while(cin >> N){
			memset(vet, 0, sizeof vet);
			cin >> Tracks;		
			maxSum = 0;	
			sum = 0;
			soma.clear();
			for(int j = 0; j < Tracks; j++){				
				scanf("%d", &vet[j]);
			}
			backtrack(0, 0);
			for(int unsigned j = 0; j < ans.size(); j++){
				printf("%d ", ans[j]);
			}
			printf("sum:%d\n", maxSum);
	}
	return 0;
}

