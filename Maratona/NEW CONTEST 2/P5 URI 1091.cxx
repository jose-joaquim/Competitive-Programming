#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int ct;
	while(scanf("%d", &ct) && ct){
		int x, y;
		vector<pair<int, int> > coord;
		scanf("%d %d", &x, &y);
		for(int i = 0; i < ct; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			//coord.push_back(make_pair(u, v));
			if(u > x && v > y){
				printf("NE\n");
			}else if(u < x && v > y){
				printf("NO\n");
			}else if(u < x && v < y){
				printf("SO\n");
			}else if(u > x && v < y){
				printf("SE\n");
			}else{
				printf("divisa\n");
			}
		}
	}
	return 0;
}

