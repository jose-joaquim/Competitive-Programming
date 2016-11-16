#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m, k;
int t;

int main(int argc, char **argv)
{
	scanf("%d", &t);
	while(t--){
		vector<int> menores;
		scanf("%d %d %d", &n, &m, &k);
		int vetN[n+1][n+1], vetM[m+1][m+1];
		for(int i = 0; i < n; i++){
			scanf("%d %d", &vetN[i][0], &vetN[i][1]);
		}
		//sort(vetN.begin(), vetN.end());
		for(int i = 0; i < m; i++){
			scanf("%d %d", &vetM[i][0], &vetM[i][1]);
		}
		//sort(vetM.begin(), vetM.end());
		//printf("%d\n", solve(0, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				menores.push_back(fabs(vetN[i][0] - vetM[j][0]) + fabs(vetN[i][1] - vetM[j][1]));
			}
		}
		sort(menores.begin(), menores.end());
		int ans = 0;
		for(int i = 0; i < k; i++){
			ans += menores[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}

