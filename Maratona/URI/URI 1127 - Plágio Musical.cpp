//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1127

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <map>
#include <sstream>
#include <math.h>
#include <string>

using namespace std;

int song[100030], pattern[10010]; char notes[128] = { };
int m, t;
int szP, szT;
int back[10010];

void KMPpreprocess(){
	int i = 0, j = -1; back[0] = -1;
	while(i < t-1){
		while(j >= 0 && pattern[i] != pattern[j]) j = back[j];
		i++; j++;
		back[i] = j;
	}
}

bool kmpSearch(){
	int i = 0, j = 0;
	while(i < m){
		while(j >= 0 && song[i] != pattern[j]) j = back[j];
		i++; j++;
		if(j == t-1){
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv)
{
	while(scanf("%d %d", &m, &t) && (m || t)){
		//getchar();
		string numero;
		string p1, p2;
		char ss[10];
		notes['C'] = 0, notes['D'] = 2;
		notes['E'] = 4,	notes['F'] = 5;
		notes['G'] = 7,	notes['A'] = 9;
		notes['B'] = 11;
		int prev;
		for(int i = 0; i < m; i++){
			scanf("%s", ss);
			int a = (notes[ss[0]] + (ss[1] == '#') - (ss[1] == 'b') + 12)%12;
			if(i) song[i - 1] = (prev - a + 12)%12;
			prev = a;
		}
		for(int i = 0; i < t; i++){
			scanf("%s", ss);
			int a = (notes[ss[0]] + (ss[1] == '#') - (ss[1] == 'b') + 12)%12;
			if(i) pattern[i - 1] = (prev - a + 12)%12;
			prev = a;
		}
		KMPpreprocess();
		puts(kmpSearch() ? "S" : "N");
	}
	return 0;
}

