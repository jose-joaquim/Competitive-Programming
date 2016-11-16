#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

char grid[105][105];
char instrucoes[50050];
int n, m, s, ans;
int atualX, atualY;
int dirAtual;

//NORTE, LESTE, SUL, OESTE

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int r, int c){
	return (r >= 0 && r < n) && (c >= 0 && c < m);
}

void verifica(int r, int c){
	if(!valid(r, c)){
		return;
	}
	if(grid[r][c] == '*'){
		grid[r][c] = '.';
		ans++;
		atualX = r; atualY = c;
		return;
	}
	if(grid[r][c] == '#'){
		return;
	}
	if(grid[r][c] == '.'){
		atualX = r; atualY = c;
		return;
	}
}

int main(int argc, char **argv)
{
	while(scanf("%d %d %d", &n, &m, &s) && (n || m || s)){
		cin.ignore();
		for(int i = 0; i < n; i++){
			string linha;
			getline(cin, linha);
			for(int j = 0; j < m; j++){
				grid[i][j] = linha[j];
				if(linha[j] != '*' && linha[j] != '.' && linha[j] != '#'){
					switch(linha[j]){
						case 'N': dirAtual = 0; break;
						case 'L': dirAtual = 1;	break;
						case 'S': dirAtual = 2; break;
						case 'O': dirAtual = 3; break;	
					}
					atualX = i; atualY = j;
				}
			}
		}
		scanf("%s", instrucoes);
		grid[atualX][atualY] = '.';
		ans = 0;
		for(int i = 0; i < s; i++){
			if(instrucoes[i] == 'F'){
				verifica(atualX + dx[dirAtual], atualY + dy[dirAtual]);
			}
			if(instrucoes[i] == 'E'){
				dirAtual--;
				if(dirAtual < 0) dirAtual = 3;
			}
			if(instrucoes[i] == 'D'){
				dirAtual = (dirAtual + 1)%4;
				
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

