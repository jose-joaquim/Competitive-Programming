#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	for(int q = 0; q < ct; q++){
		int s, c, r;
		double ans = 0.0;
		scanf("%d %d %d", &s, &c, &r);
		vector<int> vel;
		for(int i = 0; i < s; i++){
			int u;
			scanf("%d", &u);
			vel.push_back(u);
		}
		sort(vel.begin(), vel.end());
		for(int i = 0; i < c; i++){
			vel[i] += r;
		}
		for(int i = 0; i < s; i++){
			ans += (double)(1/(double)vel[i]);
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}

