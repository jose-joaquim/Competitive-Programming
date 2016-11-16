#include <stdio.h>
#include <stdlib.h>

typedef struct time{
       int numero;
       int pontos;
       int marcados;
       int tomados;
}times;
 
int ordem(const void *a, const void *b)
{
    struct time *ia = (struct time *)a; 
    struct time *ib = (struct time *)b;
    //
    if(ib->pontos != ia->pontos)
        return ib->pontos - ia->pontos;
    //
    if(ib->tomados == 0) ib->tomados = 1;
    if(ia->tomados == 0) ia->tomados = 1;
    if((double)ib->marcados/(double)ib->tomados != (double)ia->marcados/(double)ia->tomados){
		return (double)ib->marcados/(double)ib->tomados - (double)ia->marcados/(double)ia->tomados;
        /*if((float)ib->marcados/(float)ib->tomados - (float)ia->marcados/(float)ia->tomados > 0)
            return 1;
        else
            return -1;*/
    }
    //
    if(ib->marcados != ia->marcados)
        return ib->marcados - ia->marcados;
    //
    return ib->numero - ia->numero;    
}

int main(int argc, char **argv)
{
	int x, y, z, w, i, numT, q, h = 0;
	scanf("%d", &numT);
	while(numT != 0){
		h++;
		q = numT*(numT-1)/2;
		times qtim[numT];
		for(i = 0; i<numT; i++){
			qtim[i].numero = i+1;
			qtim[i].pontos = 0;
			qtim[i].marcados = 0;
			qtim[i].tomados = 0;
		}
		for(i = 0;i<q; i++){
			scanf("%d %d %d %d", &x, &y, &z, &w);
            if(qtim[x-1].numero == 0) qtim[x-1].numero = x;
             if(qtim[z-1].numero == 0) qtim[z-1].numero = z;
                  qtim[x-1].marcados += y;
                  qtim[x-1].tomados += w;
                  qtim[z-1].marcados += w;
                  qtim[z-1].tomados += y;
             if(y - w > 0){
                  qtim[x-1].pontos += 2;
                  qtim[z-1].pontos += 1;
             }else{
                   qtim[z-1].pontos += 2;
                   qtim[x-1].pontos += 1;
             }
		}
		qsort(&qtim, numT, sizeof(times), ordem);
		printf("Instancia %d\n", h);
		for(i=0;i<numT;i++){
			printf("%d ", qtim[i].numero);
		}
		scanf("%d", &numT);
		if(numT == 0){
			break;
		}else printf("\n\n");
	}
	return 0;
}
