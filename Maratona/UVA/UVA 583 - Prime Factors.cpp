//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=524

#include <bitset>  
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;
vi primes;   

void sieve(ll upperbound) {         
  _sieve_size = upperbound + 1;                 
  bs.set();                                         
  bs[0] = bs[1] = 0;                                    
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
  
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);  
} }      

vi primeFactors(ll N) {   
  vi factors;                 
  ll PF_idx = 0, PF = primes[PF_idx];    
  while (N != 1 && (PF * PF <= N)) {   
    while (N % PF == 0) { N /= PF; factors.push_back(PF); }   
    PF = primes[++PF_idx];                           
  }
  if (N != 1) factors.push_back(N);    
  return factors;         
}

int main(int argc, char **argv)
{
  sieve(10000000);
  int n;
  while(scanf("%d", &n) && n){
    bool menor_q_0 = false;
    if(n < 0) menor_q_0 = true;
		
    printf("%d =", n);
    if(menor_q_0){
      printf(" -1");
      vi r = primeFactors((int)fabs(n));
      for(vi::iterator i = r.begin(); i != r.end(); i++){
	printf(" x");
	printf(" %d", *i);
      }
    }else{
      vi r = primeFactors((int)fabs(n));
      printf(" %d", r[0]);
      for(vi::iterator i = r.begin()+1; i != r.end(); i++){
	printf(" x %d", *i);
      }
    }
    puts("");
  }
  return 0;
}

