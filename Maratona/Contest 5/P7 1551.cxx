#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	string frase;
	int n;	
	scanf("%d", &n);
	fflush(stdin);
	for(int i = 0; i<n;i++){
		set<char> con;
		getline(cin, frase);
		fflush(stdin);
		for(unsigned int j = 0; j < frase.length(); j++){
			if(frase[j] != ' ' && frase[j] != ','){
				con.insert(frase[j]);
			}
		}
		if(con.size()<13)
			cout<<"frase mal elaborada"<<endl;
		else if(con.size()==26)
			cout<<"frase completa"<<endl;
		else
			cout<<"frase quase completa"<<endl;
	}
	return 0;
}

