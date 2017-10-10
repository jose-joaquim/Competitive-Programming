#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

long long howMany;
long long n, a, b, c;

int main(int argc, char **argv)
{
  cin >> n >> a >> b >> c;
  /*if(!(n % 4)){
    printf("0\n");
  }else{
	howMany = 4 - (n % 4);//quantos faltam pra chegar a um multiplo de 4
	//	printf("Faltam %d pra chegar a um multiplo de 4\n", howMany);
	if(howMany == 1){
	  printf("%I64d\n", min(a, min(a + b, 3*c)));
	}else if(howMany == 2){
	  long long x = a * 2;
	  printf("%I64d\n", min(x, min(b, 2*c)));
	}else if(howMany == 3){
	  long long x = a * 3;
	  long long y1 = b + a;
	  printf("%I64d\n", min(x, min(y1, c)));
	}
  }	*/

  n %= 4;
  if(n == 0) puts("0");
  else if(n == 1) printf("%I64d\n", min(3*a, min(b + a, c)));
  else if(n == 2) printf("%I64d\n", min(2*a, min(b, 2*c)));
  else if(n == 3) printf("%I64d\n", min(a, min(b + c, 3*c)));
  return 0;
}

