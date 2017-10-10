//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2092
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int memo[1005][1005];
char A[1005];

int palindromo(int l, int r){
	if(memo[l][r] != -1) return memo[l][r];
	
	if(l == r) return memo[l][r] = 1;
	if(l + 1 == r){
		if(A[l] == A[r]){
			return memo[l][r] = 2;
		}else return memo[l][r] = 1;
	}
	
	if(A[l] == A[r]){
		memo[l][r] = 2 + palindromo(l + 1, r - 1);
	}else{
		memo[l][r] = max(palindromo(l, r - 1), palindromo(l + 1, r));
	}
	
	return memo[l][r];
}

int main(int argc, char **argv)
{
	int tc;
	scanf("%d", &tc);
	getc(stdin);
	while (tc--) {
		gets(A);
		if (strlen(A) == 0) {
			printf("0\n");
			continue;
		}
		memset(memo, -1, sizeof(memo));
		int ans = palindromo(0, strlen(A) - 1);
		printf("%d\n", ans);
	}
	/*int ct;
	scanf("%d", &ct);
	for(int l = 0; l < ct; l++){
		fflush(stdin);
		getline(cin, A);
		int length = A.size();
		//fprintf(stdout, "tamanho %d\n", length);
		if(length == 0){
			printf("0\n");
		}else{
			memset(memo, -1, sizeof memo);
			palindromo(0, length-1);
			printf("%d\n", memo[0][length-1]);
		}
	}*/
	return 0;
}

