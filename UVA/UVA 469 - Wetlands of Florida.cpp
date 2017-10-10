//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<string> matrix;
int visited[100][100];
int m, n;


int floodfill(int r, int c, char c1, char c2){
	if(r < 0 || r >= m || c < 0 || c >= n){ /*puts("oi'"); */return 0; }
	if(matrix[r][c] != c1) { /*puts("asdas"); */return 0; }
	matrix[r][c] = c2;
	int ans = 1;
	
	for(int d = 0; d < 8; d++){
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	}
	return ans;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int l = 0; l < ct; l++){
		getchar();
		string s;
		int row, col;
		fflush(stdin);
		getline(cin, s);
		while(1){
            if (s.length() > 0 && (s[0] == 'L' || s[0] == 'W'))
            {
                matrix.push_back(s);
            }
            else
            {
                break;
            }
            getline(cin, s);
		}
		m = (int) matrix.size();
		n = (int) matrix[0].size();
		cin >> row >> col;
		//cout << matrix[row-1][col-1] << endl;
		printf("%d\n", floodfill(--row, --col, 'W', '.'));
	}
	return 0;
}

