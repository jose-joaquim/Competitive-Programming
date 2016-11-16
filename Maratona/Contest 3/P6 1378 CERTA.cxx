#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

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

typedef vector<long long> vi;

int main(int argc, char **argv)
{
	int n, i, j, q = 1;
	long long soma;
	scanf("%d", &n);
	while(n != 0){		
		soma = 0;
		ponto point[n]; vi distance(n, 0);		
		for(i=0;i<n;i++){
			scanf("%I64u %I64u", &point[i].x, &point[i].y);
		}
		for(i=0;i<n;i++){
			q = 1;
			for(j=0;j<n;j++){
				distance[j] = dist(point[i], point[j]);
			}
			sort(distance.begin(), distance.end());
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

