//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=725

#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int m, n;
vector<string> matrix;


void floodfill(int r, int c, char c1, char c2){
	if(matrix[r][c] != c1){ return; }
	matrix[r][c] = c2;
	for(int d = 0; d < 8; d++){
		floodfill(r + dr[d], c + dc[d], c1, c2);
	}
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	bool resp = true;
	for(int l = 0; l < ct; l++){
		matrix.clear();
		if(resp){
			getchar();
			resp = false;
		}
		string s;
		while(getline(cin, s)){
			if(s[0] == '_'){
				matrix.push_back(s);
				break;
			}else{
				matrix.push_back(s);
			}
		}
		m = (int) matrix.size();
		
		for(int i = 0; i < m-1; i++){
			for(int j = 0; j < (int) matrix[i].size(); j++){
				if(matrix[i][j] == '*'){
					matrix[i][j] = ' ';
					floodfill(i, j, ' ', '#');
				}
			}
		}
		
		for(int i = 0; i < m; i++){
			cout << matrix[i] << endl;
		}
	}
	return 0;
}

