//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2353
#include <bitset>  
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;  
vi primes;   


// first part

void sieve(ll upperbound) {    
  _sieve_size = upperbound + 1;
  bs.set();                    
  bs[0] = bs[1] = 0;           
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
      
      for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
      primes.push_back((int)i);
    } }

bool isPrime(ll N) {             
  if (N <= _sieve_size) return bs[N];        
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;                  
}                    

int main() {
  sieve(10000000);
  int n; cin >> n;
  if(isPrime(n)) cout << n << endl;
  else{
    for(int i = n-1; i >= 2; i--){
      if(isPrime(i)){
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
