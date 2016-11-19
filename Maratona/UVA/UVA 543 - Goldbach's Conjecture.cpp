//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=484

#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;
map<int, bool> isPrime;

void sieve(long long upper_bound) {
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i <= upper_bound + 1; i++) {
        if(bs[i]) {
            for(long long j = i * i; j <= upper_bound + 1; j += i)
                bs[j] = 0;
            primes.push_back((int) i);
            isPrime[i] = true;
        }
    }
}

int main(int argc, char **argv)
{
	int n;
	sieve(10000000);
	/*for(int i = 0; i < 20; i++) printf("%d ", primes[i]);
	puts("");*/
	while(scanf("%d", &n) && n){
		int i;
		for(i = 0; i < (int) primes.size(); i++){
			if(isPrime[n - primes[i]]){
				//printf("i eh %d e primes[i] eh %d\n", i, primes[i]);
				break;
			}
		}
		printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
	}
	return 0;
}
