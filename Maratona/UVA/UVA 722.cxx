#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int m, n;
int A, B;
char matrix[100][100];

int floodfill(int r, int c, char c1, char c2){
	if(r < 0 || r >= m || c < 0 || c >= n){
		return 0;
	}
	if(matrix[r][c] != c1){ return 0; }
	matrix[r][c] = c2;
	int ans = 1;
	for(int d = 0; d < 4; d++){
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	}
	return ans;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int l = 0; l < ct; l++){
		scanf("%d %d\n", &A, &B);
		m = 0; n = 0;
		char s[110];
		while(gets(s) && strlen(s) > 0){
			//printf("%lld\n", strlen(s));
			strcpy(matrix[m], s);
			m++;
		}
		n = strlen(matrix[0]);
		printf("%d\n", floodfill(--A, --B, '0', '1'));
		if(l < ct-1) printf("\n");
	}
	return 0;
}
