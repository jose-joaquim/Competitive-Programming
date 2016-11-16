#include <stdio.h>

int posicaoRatoQueVaiSerSaciado(int ratos[], int size, int alimento) {
  int pos = -1, maior = -1;
  
  int i;
  for (i = 0; i < size; i++) {
    if(ratos[i] <= 0) continue;
    if (ratos[i] <= alimento && ratos[i] > maior) {
      maior = ratos[i];
      pos = i;
    }
  }
  
  return pos;
}

int posicaoRatoComMaiorFome(int ratos[], int size) {
  int maiorFome = -1, pos = -1;
  
  int i;
  for (i = 0; i < size; i++) {
    if (ratos[i] <= 0) {
      continue;
    }
    
    if (ratos[i] > maiorFome) {
      maiorFome = ratos[i];
      pos = i;
    }
  }
  
  return pos;
}

int main()
{
	int N, M, i;
	int saciados;
	while(scanf("%d %d", &N, &M) != EOF){
		saciados = 0;
		
		int ratos[N], alimentos[M];
		for(i=0;i<N;i++){
			scanf("%d", &ratos[i]);
		}
		
		for(i=0;i<M;i++){
			scanf("%d", &alimentos[i]);
		}
		
		for(i=0;i<M;i++){
		  int posicao = posicaoRatoQueVaiSerSaciado(ratos, N, alimentos[i]);
		  if (posicao == -1)  {
		    posicao = posicaoRatoComMaiorFome(ratos, N);
		  }
		  if (posicao != -1) {
		    ratos[posicao] -= alimentos[i];
		  }
		}
		
		for(i = 0;i<N;i++){
			if(ratos[i] <= 0){
				saciados++;
			}
		}
		printf("%d\n", saciados);
	}
	return 0;
}


