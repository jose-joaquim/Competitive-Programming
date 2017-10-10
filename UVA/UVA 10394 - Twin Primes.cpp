//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1335

#include <bitset>   // compact STL for Sieve, more efficient than vector<bool>!
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<20000010> bs;   
vector<long long> primes;  
vector<pair<long long, long long> > pairs;
map<long long, bool> isPrime;

void sieve(ll upperbound) {         
  _sieve_size = upperbound + 1;                   
  bs.set();                                             
  bs[0] = bs[1] = 0;                                 
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i); 
    isPrime[i] = true;
} }   

int main(int argc, char **argv)
{
	int n;
	sieve(19000000);
	
	for(unsigned long long i = 0; i < primes.size(); i++){
		if(isPrime[primes[i]] && isPrime[primes[i] + 2]){
			pairs.push_back(make_pair(primes[i], primes[i] + 2));
		}
	}
	
	while(scanf("%d", &n) != EOF){
		printf("(%lld, %lld)\n", pairs[n-1].first, pairs[n-1].second);
	}
	return 0;
}

