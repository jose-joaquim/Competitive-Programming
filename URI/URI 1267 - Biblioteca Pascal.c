//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1267

#include <stdio.h>

int main()
{
	int N, D, i, j, resp;
	while(scanf("%d %d", &N, &D) && N+D){
		if(N == 0 && D == 0) break;
		int matriz[D][N];
		for(i=0;i<D;i++){
			for(j=0;j<N;j++){
				scanf("%d", &matriz[i][j]);
			}
		}	
		resp = 0;	
		
		int row, col;
		for(col = 0; col < N; col++)  {
		  int bit = 1;
		  for (row = 0; row < D; row++) {
		    bit &= matriz[row][col];
		  }
		  if (bit) {
		    resp = 1;
		    break;
		  }
		}
		puts(resp ? "yes" : "no");
	}		
	return 0;
}



