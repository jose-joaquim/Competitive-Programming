#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

#define EPS 1e-6

double soma(vector<double> &r, double H){
	double sum = 0;
	for(int i = 0; i < (int)r.size(); i++){
		if(r[i] >= H)
			sum += r[i]-H;
	}
	return sum;
}

double binary(vector<double> &r, double fim, double area){
	double lo = 0.0, hi = r[fim];
	double mid;
	while(fabs(hi-lo) >= EPS){
		mid = (lo+hi)/2;
		double aa = soma(r, mid);
		//printf("%.4lf %.4lf %.4lf \n SOMA %.4lf\n", lo, hi, mid, aa);
		if(aa > area){
			 lo = mid;
		}else if(aa < area){
			 hi = mid;
		 }else break;
	}
	return mid;
}

int main(int argc, char **argv)
{
	int a;
	double n;
	double x;
	while(cin >> n >> a && ((n != 0) || (a != 0))){
		vector<double> area;
		for(int i = 0; i < n; i++){
			cin >> x;
			area.push_back(x);
		}
		sort(area.begin(), area.end());
		if(soma(area, 0) == a){ puts(":D"); continue; }
		else if(soma(area, 0) < a){ puts("-.-"); continue; }
		printf("%.4lf\n", binary(area,n-1, a));
	}
	return 0;
}
