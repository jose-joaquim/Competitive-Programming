#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void imprimeSky(vector<int>& sky){
	for(unsigned int i = 0; i< sky.size(); i++){
		printf("%d ", sky[i]);
	}
}

int main(int argc, char **argv)
{
	int L, M, R; vector<int> sky; int q = 0;
	while(scanf("%d %d %d", &L, &M, &R)){
		
		imprimeSky(sky);		
	}
	return 0;
}

