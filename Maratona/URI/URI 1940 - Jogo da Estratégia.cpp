//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1940

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
#include <iostream>

typedef struct{
	int pos;
	int pontos;
}jogador;

int main()
{
	int j, r, pont;
	scanf("%d %d", &j, &r);
	jogador player[j];
	for(int i = 0; i < j; i++){
		player[i].pos = i+1;
	}
	for(int i = 0; i < j; i++){
		player[i].pontos = 0;
	}
	for(int i = 0; i < r; i++){
		for(int k = 0; k < j; k++){
			scanf("%d", &pont);
			player[k].pontos += pont;
		}
	}
	jogador winner;
	winner.pos = -1; winner.pontos = -1;
	for(int i = 0; i < j; i++){
		if(player[i].pontos > winner.pontos){
			winner.pos = player[i].pos;
			winner.pontos = player[i].pontos;
		}else if(player[i].pontos == winner.pontos){
			if(player[i].pos > winner.pos){
				winner.pos = player[i].pos;
			}
		}
	}
	printf("%d\n", winner.pos);
	return 0;
}

