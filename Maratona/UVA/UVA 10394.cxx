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
bitset<20000010> bs;   // 10^7 should be enough for most cases
vector<long long> primes;   // compact list of primes in form of vector<int>
vector<pair<long long, long long> > pairs;
map<long long, bool> isPrime;

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
  _sieve_size = upperbound + 1;                   // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i);  // also add this vector containing list of primes
    isPrime[i] = true;
} }   

int main(int argc, char **argv)
{
	int n;
	sieve(19000000);
	//printf("size eh %lld\n", primes.size());
	for(unsigned long long i = 0; i < primes.size(); i++){
		if(isPrime[primes[i]] && isPrime[primes[i] + 2]){
			pairs.push_back(make_pair(primes[i], primes[i] + 2));
		}
	}
	//printf("O VETOR DE PARES TEM %lld DE TAMANHO\n", pairs.size());
	while(scanf("%d", &n) != EOF){
		printf("(%lld, %lld)\n", pairs[n-1].first, pairs[n-1].second);
	}
	return 0;
}

