#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int T, n;
	cin >> T; 
	while(T--){
		int melhor = -1000000000;
		int result = -1000000000;
		int iq;
		cin >> n;
		while(n--){
			cin >> iq;
			if(melhor - iq > result){
				result = melhor - iq;
			}
			if(iq > melhor){
				melhor = iq;
			}
			cout << result << endl;
		}
		
	}
	return 0;
}

