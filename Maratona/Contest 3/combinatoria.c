#include <stdio.h>

int fatorial(int n)
{
   if (n>0)
      return n*fatorial(n-1);
   else
      return 1;
}

int permutacao(int n)
{
  return fatorial(n);
}

int arranjo(int n, int p)
{
  if (p>1)
      return n*arranjo(n-1,p-1);
   else
      return n;
}

int combinacao(int n, int p)
{
   return arranjo(n,p)/fatorial(p);
}

int main(int argc, char **argv)
{
	printf("%d\n", combinacao(4,2));
	return 0;
}

