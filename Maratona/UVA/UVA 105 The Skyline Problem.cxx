#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct t{
	int xEsq;
	int xDir;
	int h;
}tupla;

bool comparator(tupla a, tupla ax){	
	return a.xEsq < ax.xEsq;
}

int main(int argc, char **argv)
{
	vector<tupla> as(100);
	sort(as.begin(), as.end(), comparator);
	return 0;
}

