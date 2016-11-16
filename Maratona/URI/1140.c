#include <stdio.h>
#include <string.h>

int main()
{
	char frase[100];
	char T;
	int i;
	int a = strlen(gets(frase));
	strcpy(&T, &frase[0]);
	for(i=1;i<a;i++){
		if(frase[i] != ' ') continue;
		else{
			if(strcmp(&T, &frase[i+1]) == 0){
				/*printf("%c e %c\n", T, frase[i+1]);
				puts("N");
				break;*/
			}
		}
	}
	return 0;
}

