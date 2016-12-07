//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1021
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> A;
int N, M;

bool can(int X){
	int a = 1;
	int litros = 0;
	for(int i = 0; i < N; i++){
		if(A[i] > X) return false;
	}
	
	for(int i = 0; i < N; i++){
		if(litros + A[i] > X){
			a++;
			litros = A[i];
		}else{
			litros += A[i];
		} 
		
		if(a > M) return false;
	}
	return true;
}

int binary(){
	int lo = 1, hi = 1e9;
	int mid;
	int resp;
	while(lo <= hi){
		mid = (lo+hi)/2;
		if(can(mid)){
			resp = mid;
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}
	return resp;
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &N, &M) != EOF){
		A.clear();
		int k;
		for(int i = 0; i < N; i++){
			scanf("%d", &k);
			A.push_back(k);
		}
		printf("%d\n", binary());
	}
	return 0;
}

