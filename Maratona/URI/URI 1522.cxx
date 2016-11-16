#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <stack>
#include <stdlib.h>

using namespace std;

bool resp;
int ct;
int memo[102][102][102];
int stx[103], sty[103], stz[103];

int solve(int x, int y, int z){
	if(x > ct || y > ct || z > ct){//se alguem passou dos limites
		return 0;
	}
	int &ans = memo[x][y][z];
	if(x == ct && y == ct && z == ct){//se cheguei na resposta
		return ans = 1;
	}
	
	if(ans != -1){
		return ans;
	}
	ans = 0;
	
	if((stx[x] + sty[y] + stz[z])%3 == 0){
		ans = ans | solve(x+1, y+1, z+1);
	}
	if(stx[x] % 3 == 0){
		ans = ans | solve(x+1, y, z);
	}
	if(sty[y] % 3 == 0){
		ans = ans | solve(x, y + 1, z);
	}
	if(stz[z] % 3 == 0){
		ans = ans | solve(x, y, z + 1);
	}
	if((stx[x] + sty[y]) % 3 == 0){
		ans = ans | solve(x+1, y+1, z);
	}
	if((stx[x] + stz[z]) % 3 == 0){
		ans = ans | solve(x+1, y, z+1);
	}
	if((sty[y] + stz[z]) % 3 == 0){
		ans = ans | solve(x, y+1, z+1);
	}  
	return ans;
}

int main(int argc, char **argv)
{
	while(scanf("%d", &ct) && ct){
		memset(memo, -1, sizeof memo);
		resp = false;
		for(int i = 0; i < ct; i++){
			scanf("%d %d %d", &stx[i], &sty[i], &stz[i]);
		}
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}

