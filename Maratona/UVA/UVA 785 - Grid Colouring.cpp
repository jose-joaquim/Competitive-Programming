//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=726

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int m, n;
vector<string> matrix;

void floodfill(int r, int c, char c1, char c2){
	if(r < 0 || r >= m || c < 0 || c >= n) return;
	if(matrix[r][c] != c1){ return; }
	matrix[r][c] = c2;
	for(int d = 0; d < 4; d++){
		floodfill(r + dr[d], c + dc[d], c1, c2);
	}
}

int main(int argc, char **argv)
{
	string s;
	while(getline(cin, s)){
		matrix.clear();
		char c;
		matrix.push_back(s);
		while(getline(cin, s)){
			if(s[0] == '_'){
				matrix.push_back(s);
				break;
			}else{
				matrix.push_back(s);
			}
		}
		m = (int) matrix.size();
		for(int i = 0; i < (int) matrix[0].size(); i++){
			if(matrix[0][i] != ' '){
				c = matrix[0][i];
				break;
			}
		}
		for(int i = 0; i < m-1; i++){
			for(int j = 0; j < (int) matrix[i].size(); j++){
				if(matrix[i][j] != c && matrix[i][j] != ' '){
					n = (int) matrix[i].size();
					char k = matrix[i][j];
					matrix[i][j] = ' ';
					floodfill(i, j, ' ', k);
				}
			}
		}
		
		for(int i = 0; i < m; i++){
			cout << matrix[i];
			puts("");
		}
	}
	return 0;
}

