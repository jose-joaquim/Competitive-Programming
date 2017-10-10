//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1081

#include <bitset>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <map>
#include <limits.h>

#define INF 1000000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;
vector<long long> primes;
int L, U;

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
  _sieve_size = upperbound + 1;                   // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i);  // also add this vector containing list of primes
} } 

bool isPrime(ll N) {                 // a good enough deterministic prime tester
  if (N <= _sieve_size) return bs[N];                   // O(1) for small primes
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;                    // it takes longer time if N is a large prime!
}                      // note: only work for N <= (last prime in vi "primes")^2


int main(int argc, char **argv)
{
	sieve(10000000);
	while(scanf("%d %d", &L, &U) != EOF){
		bool ans = false, go = false;
		int la, lb, ua, ub, last = 0;
		int menor = INF, maior = -INF;
		for(long long i = L; i <= U; i++){
			if(isPrime(i)){
				if(!go){
					last = i;
					go = true;
				}else{
					if(i - last < menor){
						lb = last;
						la = i;
						menor = i - last;
					}
					if(i - last > maior){
						ub = last;
						ua = i;
						maior = i - last;
					}
					last = i;
					ans = true;
				}				
			}
		}
		if(!ans){
			puts("There are no adjacent primes.");
		}else{
			printf("%d,%d are closest, %d,%d are most distant.\n", la, lb, ua, ub);
		}
	}
	return 0;
}

