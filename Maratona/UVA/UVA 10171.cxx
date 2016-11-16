#include <iostream>
#include <cstdio>
#include <string.h>
#include <map>

using namespace std;

#define INF 1000000000

int main(int argc, char **argv)
{
	int N;
	while(scanf("%d", &N) && N){
		int AdjMat[30][30];
		map<pair<int, int>, char> mymap;
		
		for(int i = 0; i < 30; i++)
			for(int j = 0; j < 30; j++)
				AdjMat[i][j] = INF;
				
		//
		char a, b, c, d;
		for(int i = 0; i < N; i++){
			int w;
			scanf("%c %c %c %c %d", &a, &b, &c, &d, &w);
			int u = c - 95;
			int v = d - 95;
			if(b == 'B'){
				AdjMat[u][v] = w;
				AdjMat[v][u] = w;
				mymap[make_pair(u, v)] = a;
				mymap[make_pair(v, u)] = a;
			}else{
				AdjMat[c-65][d-65] = w;
				mymap[make_pair(u, v)] = a;
			}
		}
		
		for(int i = 0; i < 30; i++) AdjMat[i][i] = 0;
		
		for(int k = 0; k < 30; k++)
			for(int i = 0; i < 30; i++)
				for(int j = 0; j < 30; j++){
					AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
				}
					
		char A, B;
		scanf("%c %c", &A, &B);
		
		
	}
	return 0;
}

