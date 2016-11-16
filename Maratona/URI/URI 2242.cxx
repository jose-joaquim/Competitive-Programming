#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	string txt;
	while(cin >> txt){
		vector<char> pal, contrario;
		for(int i = 0; i < (int) txt.size(); i++){
			if(txt[i] == 'a' || txt[i] == 'e' || txt[i] == 'i' || txt[i] == 'o' || txt[i] == 'u'){
				pal.push_back(txt[i]);
			}
		}
		bool ans = true;
		int sz = (int) pal.size();
		for(int i = sz - 1; i >= 0; i--){
			contrario.push_back(pal[i]);
		}
		for(int i = 0; i < sz; i++){
			if(pal[i] != contrario[i]){
				ans = false;
				break;
			}
		}
		puts(ans ? "S" : "N");
	}
	return 0;
}

