#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	char cod[50], frase[51];
	int x, i, j, q;
	scanf("%d", &x);
	strcpy(cod, "\0");
	for(i = 0; i < x; i++){
		q = 0;
		gets(frase);
		fflush(stdin);
		for(j = 0; j != '\0'; j++){
			if(j != ' '){
				if(j == 0){
					break;
				}
			}
		}
		printf("%s\n", cod);				
	}
	return 0;
}

