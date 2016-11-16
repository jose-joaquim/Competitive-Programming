#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
#include <iomanip>

using namespace std;

typedef pair<int, int> ii;

/*typedef struct h{
	int people;
	int consumo;
}house;*/

/*int cmp(const void *a, const void *b){
	return ((house *)a)->consumo - ((house *)b)->consumo;
}*/

bool cmp(const ii &a, const ii &b){
	return a.second < b.second;
}

int main(int argc, char **argv)
{
	int N, cidade = 0;
	bool quebra = false;
	while(scanf("%d", &N) && N){
		int medias[205];
		memset(medias, 0, sizeof medias);
		if(quebra){
			printf("\n");
		}else quebra = true;
		int i;
		double totPeople = 0, totConsumo = 0;
		int last = -1;
		for(i = 0; i < N; i++){
			int u, v, media;//u é numero de número de pessoas e v é consumo
			scanf("%d %d", &u, &v);
			media = v/u;
			totPeople += u;
			totConsumo += v;
			medias[media] += u;
			last = max(last, media);
		}
		printf("Cidade# %d:\n", ++cidade);
		for(int i = 0; i < last; i++){
			if(medias[i]) printf("%d-%d ", medias[i], i);
		}
		printf("%d-%d\n", medias[last], last);
		printf("Consumo medio: %.2lf m3.\n", floor((totConsumo/totPeople)*100)/100);
	}
	return 0;
}

