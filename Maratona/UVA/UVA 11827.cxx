#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <string>

using namespace std;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b){ return a * (b / gcd(a, b)); }

/*int recursao(int q, vector<int> &vet){
	if(q == 0) return gcd(0, vet[0]);
	else return gcd(vet[q], recursao(q-1, vet));
}

void backtrack(){
	
	
}*/

int main(int argc, char **argv)
{
	int N;
	scanf("%d", &N);
	cin.ignore();
	for(int i = 0; i < N; i++){
		vector<int> my;
		string linha, numero = "";
		getline(cin, linha);
		stringstream ss(linha);
		while(ss >> numero){
			my.push_back(stoi(numero));
		}
		int sz = (int) my.size();
		int ans = -1;
		for(int i = sz-1; i >= 0; i--){
			for(int j = 0; j < i; j++){
				ans = max(ans, gcd(my[i], my[j]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

