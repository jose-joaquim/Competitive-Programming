#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

#define INF 1000000000

using namespace std;

int n, m, p, d, q;
int memo[101][5000];
int gasto[101], felicidade[101];
int opcoes[101][2];

int solve(int rua, int remW, int happy){
	if(remW < 0) return -INF;
	if(rua < 0 || rua >= n) return -INF;
	
	if(memo[rua][remW] != -1) return memo[rua][remW];
	
	printf("to na rua %d com %d de borracha restante %d de felicidade\n", rua, remW, happy);
	printf("posso ir pra a rua %d ou pra rua %d\n\n", opcoes[rua][0], opcoes[rua][1]);
	
	int a = solve(opcoes[rua][0], remW - gasto[rua], happy + felicidade[rua]);
	int b = solve(opcoes[rua][1], remW - gasto[rua], happy + felicidade[rua]);
	
	happy += max(a, b);
	
	return memo[rua][remW] = happy;
}

int main(int argc, char **argv)
{
	memset(memo, -1, sizeof memo);
	scanf("%d %d %d %d %d", &n, &m, &p, &d, &q);
	for(int i = 0; i < m; i++){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		opcoes[i][0] = a-1;
		opcoes[i][1] = b-1;
		felicidade[i] = c;
		gasto[i] = d;
	}
	printf("%d\n", solve(p-1, q, felicidade[p-1]));
	return 0;
}

