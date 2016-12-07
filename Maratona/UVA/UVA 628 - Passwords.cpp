//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=569

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>

using namespace std;

int n, m;
string words[10], waves[10]; int c_waves = 0;
int ss = 0;

void backtrack_n(int c, string w){	
	if(c >= c_waves){
		cout << w << endl;
	}else{
		if(waves[ss][c] == '#'){
			for(int i = 0; i < n; i++){
				backtrack_n(c+1, w + words[i]);
			}
		}else{ //0
			for(int i = 0; i <= 9; i++){
				char x = 48 + i;
				backtrack_n(c+1, w + x);	
			}		
		}		
	}
}

int main(int argc, char **argv)
{
	while(true){
		n = m = 0;		
		cin >> n;
		ss = 0;
		c_waves = 0;
		fflush(stdin);
		for(int i = 0; i < n; i++){
			getline(cin, words[i]);
			fflush(stdin);
		}
		cin >> m;
		fflush(stdin);
		for(int i = 0; i < m; i++){
			getline(cin, waves[i]);
			fflush(stdin);
		}
		printf("--\n");
		while(ss < m){
			c_waves = waves[ss].size();
			backtrack_n(0, "");
			ss++;
		}
	}
	return 0;
}

