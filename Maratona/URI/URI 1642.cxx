#include <stdio.h>
#include <iostream>
#include <string>
 
using namespace std;

string texto;
int n;

int main(int argc, char **argv)
{
    while(scanf("%d", &n) && n) {
        cin.ignore();
		getline(cin, texto);
        int ans = -1, aux = 0, cont=0;
        int letras[n+1];
        for(int i = 0; i < (int) texto.size(); ){
            bool ta = false;
            int j = 0;
            while(j < cont && !ta){
				//printf("KK entrei com i = %d E CONT EH %d\n", i, cont);
                if(texto[i] == texto[letras[j]]){
					//printf("    | entrei i eh %d\n", i);
                    aux++;
                    letras[j] = i;
                    i++;
                    ta = true;
                }
                j++;
            }
            if(!ta && cont < n){
				//printf("QS entrei com i = %d E CONT EH %d\n", i, cont);
                letras[cont] = i;
                cont++;
                i++;
                aux++;
            }else if(!ta) {
				//printf("ASentrei com i = %d E CONT EH %d\n", i, cont);
				ans = max(ans, aux);
                int menor = 0;
                for(j = 1; j < cont; j++) {
                    if(letras[j] < letras[menor]) menor = j;
                }
                aux = i - letras[menor];
                letras[menor] = i;
                i++;
            }
        }
        ans = max(ans, aux);
        printf("%d\n", ans);
    }
    return 0;
}
