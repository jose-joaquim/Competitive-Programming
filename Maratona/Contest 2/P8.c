#include <stdio.h>

int main(int argc, char **argv)
{
	int atq, def, i, temp, j;
	scanf("%d %d", &atq, &def);
	while(atq != 0 || def != 0){
		int vatq[atq], vdef[def];
		for(i = 0; i<atq; i++){
			scanf("%d", &vatq[i]);		
		}
		for(i = 0; i<def; i++){
			scanf("%d", &vdef[i]);
		}
		//ordenando os atacantes de menor > maior
		for(i = 0; i<atq; i++)
			for(j = 0; j<atq-1; j++)
				if(vatq[j] > vatq[j+1]){
					temp = vatq[j];
					vatq[j] = vatq[j+1];
					vatq[j+1] = temp;
				}
		//ordenando os defensores de menor > maior
		for(i = 0; i<def; i++)
			for(j = 0; j<def-1; j++)
				if(vdef[j] > vdef[j+1]){
					temp = vdef[j];
					vdef[j] = vdef[j+1];
					vdef[j+1] = temp;
				}
		//
		
		if(vatq[0] >= vdef[1] || ((vatq[0] == vdef[0]) && (vatq[0] == vdef[1])) ){//se dist atacante > dist defesa
			puts("N");
		}else{
			puts("Y");
		}
		scanf("%d %d", &atq, &def);
	}
		
	return 0;
}

