#include <stdio.h>

int main(int argc, char **argv)
{
	char nome[50];
	double sal, bonus;
	gets(nome);
	fflush(stdin);
	scanf("%lf %lf", &sal, &bonus);
	sal += bonus*0.15;
	printf("TOTAL = R$ %.2lf\n", sal);
	return 0;
}

