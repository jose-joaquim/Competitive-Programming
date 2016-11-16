#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char CPF[15];
	int soma[9], B1, B2, i, sum;
	while(scanf("%s", CPF)){
		sum = 0;
		soma[0] = CPF[0]-48;
		soma[1] = (CPF[1]-48)*2;
		soma[2] = (CPF[2]-48)*3;
		soma[3] = (CPF[4]-48)*4;
		soma[4] = (CPF[5]-48)*5;
		soma[5] = (CPF[6]-48)*6;
		soma[6] = (CPF[8]-48)*7;
		soma[7] = (CPF[9]-48)*8;
		soma[8] = (CPF[10]-48)*9;
		for(i=0;i<9;i++){
			sum += soma[i];
		}
		//
		if(sum%11 == 10){
			B1 = 0;
		}else B1 = sum%11;
		//
		sum = 0;
		soma[0] = (CPF[0]-48)*9;
		soma[1] = (CPF[1]-48)*8;
		soma[2] = (CPF[2]-48)*7;
		soma[3] = (CPF[4]-48)*6;
		soma[4] = (CPF[5]-48)*5;
		soma[5] = (CPF[6]-48)*4;
		soma[6] = (CPF[8]-48)*3;
		soma[7] = (CPF[9]-48)*2;
		soma[8] = (CPF[10]-48)*1;
		for(i=0;i<9;i++){
			sum += soma[i];
		}
		if(sum%11 == 10){
			B2 = 0;
		}else B2 = sum%11;
		
		if(B1 == (CPF[12]-48) && B2 == (CPF[13]-48)){
			puts("CPF valido");
		}else puts("CPF invalido");
	}
	return 0;
}

