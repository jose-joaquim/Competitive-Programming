#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)

int main(int argc, char **argv)
{
	int N, C, i;
	int lucro = 0, ans = 0;
	scanf("%d %d", &N, &C);
	int cap[N];
	for(i = 0; i < N; i++){
		scanf("%d", &cap[i]);
	}
	cap[0] += C;
	int aux = 0;
	int newZero = 0;
	int montante = 0;
	for(i = 1; i < N; i++){
		aux = cap[i]-cap[i-1];
		lucro += aux;
		montante = max(montante, lucro);
		//printf("montante eh %d em cap[%d]\n", montante, i+1);
		if(lucro < 0){
			if(lucro < newZero){
				/*printf("MONTANTE EH %d\n", montante);
				printf("atualizando o valor de cap[%d] de %d para %d\n", i+1, cap[i], cap[i] + C);*/
				ans += montante;
				newZero = lucro;
				lucro = 0;
				cap[i] += C;
				montante = 0;
				//printf("newZero eh %d\n", newZero);
			}
		}else{
			//printf("vou somar %d a ans\n", aux);
			//ans += montante;
		}
	}
	if(montante > 0) ans += montante;
	printf("%d\n", ans);
	return 0;
}

