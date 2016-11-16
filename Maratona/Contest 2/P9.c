#include <stdio.h>

int main(int argc, char **argv)
{
	int x, i, cfinal, cdias;
	int dia, mes, ano, c;
	scanf("%d", &x);
	while(x != 0){
		cfinal = cdias = 0;
		int matriz[x][4];
		for(i=0; i<x; i++){
			scanf("%d %d %d %d", &dia, &mes, &ano, &c);
			matriz[i][0] = dia;
			matriz[i][1] = mes;
			matriz[i][2] = ano;
			matriz[i][3] = c;
		}
		if(!(ano%4)){//se o ano eh bissexto
			
		}else{
			
		}		
		scanf("%d", &x);
	}
	return 0;
}

