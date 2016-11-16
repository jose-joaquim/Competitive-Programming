#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int memo[105][105];
int sz1, sz2;
char seq1[105], seq2[105];

int solve(int x, int y){
	if(x >= sz1 || y >= sz2) return 0;
	
	if(memo[x][y] != -1){
		return memo[x][y];
	}
	
	if(seq1[x] == seq2[y]){
		return memo[x][y] = 1 + solve(x + 1, y + 1);
	}else{
		return memo[x][y] = max(solve(x + 1, y), solve(x, y + 1));
	}
	
	return memo[x][y];
}

int main(int argc, char **argv)
{
	int cs = 0;
	while(scanf("%s", seq1) && seq1[0] != '#'){
		//memset(memo, -1, sizeof memo);
		scanf("%s", seq2);
		sz1 = (int) strlen(seq1);
		sz2 = (int) strlen(seq2);
		
		for(int i = 0; i < sz1; i++){
			for(int j = 0; j < sz2; j++){
				memo[i][j] = -1;
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n", ++cs, solve(0, 0));
	}
	return 0;
}

