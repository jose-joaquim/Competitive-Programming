//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1133

#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

char seq1[105], seq2[105];

int main(int argc, char **argv)
{
	while(scanf("%s", seq1) && seq1[0] != '#'){
		scanf("%s", seq2);
		int a = (int) strlen(seq1);
		int b = (int) strlen(seq2);
		int memo[105][105];
		memset(memo, 0, sizeof memo);	
		
		memo[0][0] = 0;
		for(int i = 1; i <= a; i++) memo[i][0] = i * -1;
		for(int j = 1; j <= b; j++) memo[0][j] = j * -1;
	} 
	return 0;
}

