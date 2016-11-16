#include <stdio.h>

int main(int argc, char **argv)
{
	char C;
	float matriz[12][12];
	float soma = 0, soma1 = 0, soma2 =0;
	int i, j;
	fgets(&C, 1, stdin);
	for(i = 0; i < 12; i++){
		for(j = 0; j < 12; j++){
			scanf("%f", &matriz[i][j]);
		}
	}
	for(j = 0; j < 5; j++){
		for(i = j+1; i < 6; i++){
			soma1 += matriz[i][j];
		}
		for(i = 10 - j; i > 5; i--){
			soma2 += matriz[i][j];
		}
		soma = soma1 + soma2;
	}
	switch(C){
		case 'S': printf("%.1f\n", soma); break;
		case 'M': printf("%.1f\n", soma/30); break;
	}
	return 0;
}
/*#include <stdio.h>
   
#define MAX 12 
int main(){
   
   
int i,j,n=0,cont=0;
double M[MAX][MAX],soma1=0,soma2=0,soma3=0;
char t;
    scanf("%c", &t);
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            scanf("%lf", &M[i][j]);
        }
    }
    for(j=0;j<5;j++){
        for(i=j+1;i<6;i++){
        soma1 += M[i][j];
        }
        for(i=10-j;i>5;i--){
        soma2 += M[i][j];
        }   
        soma3=soma1+soma2;
    }       
              
 
 
    if(t=='S'){printf("%.1lf\n",soma);}
    else{ printf("%.1lf\n",soma/30);}
}*/

