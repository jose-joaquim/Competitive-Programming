/* URI 1738 */

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
	int n;
	while(scanf("%d", &n) && n){
		int AdjMat[n][n];
		memset(AdjMat, 0, sizeof AdjMat);
		char empresas[30];
		int u, v;
		while(scanf("%d %d", &u, &v) && (u || v)){
			scanf("%s", empresas);
			int i = 0, num = 0;
			while(i < (int) strlen(empresas)){
				num |= (1 << (empresas[i]-97));
				i++;
			}
			AdjMat[u-1][v-1] = num;
		}
		
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);
					
		while(scanf("%d %d", &u, &v) && (u || v)){
			for(int i = 0; i < 26; i++){
				int c = (AdjMat[u-1][v-1] & (1 << i));
				if(c != 0){
					printf("%c", i + 97);
				}
				else printf("-\n");
			}
			puts("");
		}
	}
	return 0;
}

