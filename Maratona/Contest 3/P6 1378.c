#include <stdio.h>
#include <stdlib.h>
#include "bubble.h"

typedef struct{
	long long x;
	long long y;
}ponto;

long long combinatoria(long long x, long long p){
	return (x*(x-1))/2;
}

long long dist(ponto a, ponto b){
	return ((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}

void heapsort(long long *a, int n) {

   int i = n / 2, pai, filho, t;

   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }

      pai = i;
      filho = i * 2 + 1;

      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

int main(int argc, char **argv)
{
	int n, i, j, q = 1;
	long long soma;
	scanf("%d", &n);
	while(n != 0){		
		soma = 0;
		ponto point[n]; long long distance[n];		
		for(i=0;i<n;i++){
			scanf("%I64u %I64u", &point[i].x, &point[i].y);
		}
		for(i=0;i<n;i++){
			q = 1;
			for(j=0;j<n;j++){
				distance[j] = dist(point[i], point[j]);
			}
			//heapsort(distance, n+1);
			bubble(distance, n);
			j=0;
			while(j <= n-1){
				if(distance[j] == distance[j+1]){
					j += 2;
					while(distance[j] == distance[j+1]){
						j += 2;
						q *= 2;
					}				
					soma += combinatoria(2*q, 2);					
				}else{
					j++;
				}
			}	
		}
		printf("%I64u\n", soma);		
		scanf("%d", &n);
	}	
	return 0;
}

