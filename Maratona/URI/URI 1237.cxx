#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	string a, b;
	getline(cin, a);
	while(getline(cin, b)){
		int ans = 0;
		
		int limA = (int) a.size();
		int limB = (int) b.size();
		
		for(int i = 0; i < limA; i++){
			for(int j = 0; j < limB; j++){
				if(a[i] == b[j]){
					int cont = 0;
					for(int k = 0; k + i < limA && k + j< limB; k++){
						if(a[k+i] != b[k+j]) break;
						cont++;
					}	
					ans = max(ans, cont);				
				}
				/*if(aux < limA && a[aux] == b[j]){
					cont++;
					aux++;
				}else if(aux >= limA) break;*/
			}
		}
		printf("%d\n", ans);
		getline(cin, a);
	}
	return 0;
}

