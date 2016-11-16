#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

int mark[1000100];

int main(int argc, char **argv)
{
	int n;
	while(scanf("%d", &n) && n){
		int vet[n+1];
		memset(mark,0,sizeof mark);
		int ans = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &vet[i]);
			int v = vet[i];
			if (mark[v]){
				ans += i - mark[v];
				mark[v]=i;
			}else{
				ans += i -1 + v;
				mark[v]=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

