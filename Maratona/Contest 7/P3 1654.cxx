#include <cstdio>
#include <cmath>
using namespace std; 

int main(int argc, char **argv)
{
	int p1, p2, p3;	
	for(p1 = 1; 4*p1 <= 2000; p1++){
		if(pow(p1, 4) > 2*1e+9) break;		
		for(p2 = p1; p1 + 3*p2 <= 2000; p2++){
			if(pow(p2, 3) > (2*1e+9)-p1) break;						
			for(p3 = p2; p1 + p2 + 2*p3 <= 2000; p3++){	
				if(pow(p3, 2) > (2*1e+9)-p2-p1) break;	
				long long p = (p1 * p2 * p3); 
				long long s = (p1 + p2 + p3); 
				if (p <= 1000000) 
 					continue; 
				if(1000000*s%(p-1000000)==0){
					long long p4 = (1000000 * s) / (p - 1000000); 
					if (p4 < p3 || s + p4 > 2000) 
						continue; 
					printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", p1 / 100.0, 
								p2 / 100.0, p3 / 100.0, p4 / 100.0); 
				}
			}			
		}
	}
	return 0;
}

