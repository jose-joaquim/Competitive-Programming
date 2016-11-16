#include <stdio.h>
#include <math.h>

int main () 
{
	int i, j;    
    int t, l, bs, iv, ev, hp, S[3];
    char n[12];
    int aux;
    
    scanf("%d", &t);
    for(i = 0; i<t; i++){
		scanf("%s %d", n, &l);
		scanf ("%d %d %d", &bs, &iv, &ev); 
		aux = sqrt(ev) / 8;    
		hp = ((iv + bs + aux + 50) * l) / 50 + 10;
		for(j=0; j<3; j++){
			scanf ("%d %d %d", &bs, &iv, &ev);    
			S[j] = ((iv + bs + aux) * l) / 50 + 5;
		}		   
		printf("Caso #%d: %s nivel %d\n", (i+1), n, l);
		printf("HP: %d\n", hp);
		printf("AT: %d\n", S[0]);
		printf("DF: %d\n", S[1]);
		printf("SP: %d\n", S[2]);
    }
    return 0;
}
