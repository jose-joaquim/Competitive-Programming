#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

int main(int argc, char **argv)
{	
	/*bitset<11> number(6);
	cout << number << endl;*/
	//int a = 0;
	//printf("%d\n", number[2] & (1 << 2));
	int ct;
	while(scanf("%d", &ct) && ct){
		bitset<11> number(ct);
		//printf("%lld\n", number.size());
		//cout << number << endl;
		int a = 0, b = 0;
		for(int i = 0; i < 11; i++){
			//cout << number[i] << endl;
			if(i%2 == 0){//vai pertencer a 'b'
				if(number[i] == 1)	b |= (1 << i);
			}else if(number[i] == 1) a |= (1 << i); 
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}

