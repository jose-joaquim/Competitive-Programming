#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
	char c;
	string num;
	while(cin >> c >> num && (c != '0' && num[0] != '0')){
		string ans;
		for(int i = 0; i < (int) num.size(); i++){
			if(num[i] != c){
				ans += num[i];
			}
		}
		int sz = (int) ans.size();
		if(!sz){
			puts("0");
		}else{
			int j = 0;
			while(ans[j] == '0') j++;
			if(j == sz) puts("0");
			else{
				for(int i = j; i < sz; i++) printf("%c", ans[i]);
				puts("");
			}
		}
	}
	return 0;
}

