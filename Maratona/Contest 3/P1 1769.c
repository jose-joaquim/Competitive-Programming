#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ehcpf(char CPF[]){
	int soma = 0, v = 0, i;
	for(i = 0; i<11; i++){
		if(i == 4 || i == 8 || i == 12)	continue;
		v = atoi(&CPF[i]);
		printf("%d\n", v);
	}
}

int main(int argc, char **argv)
{
	char CPF[14];
	int i = 0;
	while(i < 10000){
		gets(CPF);
		ehcpf(CPF);
		i++;
	}
	return 0;
}

