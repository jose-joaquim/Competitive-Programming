#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A;
int size;

bool can(int K){
	if(A[0] > K) return false;
	if(A[0] == K) K--;
	if(K < 0) return false;
	for(int i = 1; i < size; i++){
		if(A[i] - A[i-1] > K){
			return false;
		}else if(A[i] - A[i-1] == K){
			K--;
		}
		
		if(K < 0) return false;
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
	int ct;
	scanf("%d", &ct);
	for(int q = 1; q <= ct; q++){
		int qtd, k;
		A.clear();
		cin >> qtd;
		for(int i = 0; i < qtd; i++){
			cin >> k;
			A.push_back(k);
		}
		size = (int) A.size();
		printf("Case %d: %d\n", q, binary());
	}
	return 0;
}

