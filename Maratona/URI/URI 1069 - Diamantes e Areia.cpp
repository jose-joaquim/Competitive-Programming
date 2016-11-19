//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1069

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <iostream>

using namespace std;

int main()
{	
	string frase;
	int x, diamantes;
	scanf("%d", &x);
	fflush(stdin);
	for(int i = 0; i<x; i++){
		stack<char> pilha;
		diamantes = 0;
		getline(cin, frase);
		fflush(stdin);
		for(unsigned int j = 0; j<frase.length(); j++){
			switch(frase[j]){
				case '<':
					pilha.push(frase[j]);
					break;
				case '>':
					if(pilha.size()){
						diamantes++;
						pilha.pop();
					}
					break;
			}	
		}
		printf("%d\n", diamantes);
	}
	return 0;
}

