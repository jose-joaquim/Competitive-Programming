//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2050

#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

int m;
int matrix[10][10];
map<int, string> int_string;
map<string, int> string_int;

void backtrack(int c, vector<int> &el, int qtd){
	if(qtd == 3){
		if(matrix[el[0]][el[1]] == matrix[el[0]][el[2]] && matrix[el[0]][el[1]] == matrix[el[1]][el[2]]){
			if(matrix[el[0]][el[1]] == 1){
				//sao amigos
				cout << int_string[el[0]] << " " << int_string[el[1]] << " " << int_string[el[2]] << " ";
				printf("sao amigos\n");
			}else{
				//sao inimigos
				cout << int_string[el[0]] << " " << int_string[el[1]] << " " << int_string[el[2]] << " ";
				printf("sao inimigos\n");
			}
		}
		return;
	}
	for(int i = c; i < 6; i++){
		vector<int> opa(el);
		opa.push_back(i);
		backtrack(i + 1, opa, qtd + 1);
	}
}

int main(int argc, char **argv)
{
	int cs = 0;
	bool quebra = false;
	while(scanf("%d", &m) && (m != -1)){
		if(!quebra){
			quebra = true;
		}else puts("");
		memset(matrix, 0, sizeof matrix);
		int_string.clear();
		string_int.clear();
		vector<string> nomes;
		for(int i = 0; i < 6; i++){
			string nome;
			cin >> nome;
			nomes.push_back(nome);
		}
		sort(nomes.begin(), nomes.end());
		for(int i = 0; i < 6; i++){
			string_int[nomes[i]] = i;
			int_string[i] = nomes[i];
		}
		
		for(int i = 0; i < m; i++){
			string a, b;
			cin >> a >> b;
			matrix[string_int[a]][string_int[b]] = 1;
			matrix[string_int[b]][string_int[a]] = 1;
		}
		printf("Instancia %d\n", ++cs);
		vector<int> vet;
		backtrack(0, vet, 0);
	}
	return 0;
}

