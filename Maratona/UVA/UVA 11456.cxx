#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
	int ct;
	cin >> ct;
	while(ct--){
		int num, a;
		cin >> num;
		vector<int> A;
		vector<int> lengthI(num), lengthD(num);
		int LIS = 0;
		for(int i = 0; i < num; i++){
			cin >> a;
			A.push_back(a);
			lengthI[i] = 1;
			lengthD[i] = 1;
		}
		for(int i = num-1; i >= 0; i--){
			for(int j = i+1; j < num; j++){
				if(A[j] < A[i] && lengthI[j] + 1 > lengthI[i]){
					lengthI[i] = lengthI[j] + 1;
				}
			}
			
			for(int j = i+1; j < num; j++){
				if(A[j] > A[i] && lengthD[j] + 1 > lengthD[i]){
					lengthD[i] = lengthD[j] + 1;
				}
			}
		}
		for(int i = 0; i < num; i++){
			LIS = max((lengthI[i] + lengthD[i] - 1), LIS);
		}
		printf("%d\n", LIS);
	}
	return 0;
}

