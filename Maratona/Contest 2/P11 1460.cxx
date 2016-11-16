#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
using namespace std;

const int MAX_ROW = 505;
const int MAX_COL = 505;

// int busca_bin_r(vector<int>& vetor, int tamanho, int valor) {
// 	int inf = 0, sup = tamanho - 1;
// 	int mid = (sup + inf) / 2;
// 	int lowb = -1;
// 	while(sup >= inf) {
// 		if(valor <= vetor[mid]) {
// 			if(vetor[mid] >= lowb)lowb=mid;
// 			sup = mid - 1;
// 		}
// 		else{
// 			inf = mid + 1;
// 		}
// 		mid = (sup + inf) / 2;
		
// 	}
// 	return lowb;//(vetor[i] >= valor) ? (i) : (-1);
// }

/*
  LowerBound: first not less than
  UpperBound: first greater than
 */
int getBound(vector<int> &grid, int v, int last_position) {
  int lo = 0, hi = last_position;
  while (lo <= hi) {
    int mid = (lo+hi)/2;
    if (grid[mid] < v)
      lo = mid+1;
    else
      hi = mid-1;
  }
  return hi+1;
}

vector< vector<int> > matriz(MAX_ROW, vector<int>(MAX_COL));

int main(){
	int m,n;
	while(scanf("%d %d", &m, &n) && m+n){
		int i,j;
		
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d",&matriz[i][j]);
			}
		}
		
		int nconsultas;
		scanf("%d",&nconsultas);
		for(i=0;i<nconsultas;i++){
			int lowb;
			int uppb;
			scanf("%d %d",&lowb, &uppb);
			
			int tamanho=0;
			for (int i = 0; i < m; i++) {
				int k = getBound(matriz[i], lowb, n-1);
				int aumentando_tamanho = tamanho;
				while (i+aumentando_tamanho < m &&
				   k+aumentando_tamanho < n &&
		           matriz[i][k] >= lowb && 
		           matriz[i+aumentando_tamanho][k+aumentando_tamanho] <= uppb)
		           aumentando_tamanho++;
				tamanho = aumentando_tamanho;
			}
			printf("%d\n",tamanho);
		}
		printf("-\n");
	}	
	
	return 0;
}
