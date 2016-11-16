#include <iostream>
#include <cstdio>

using namespace std;

#define MOD 131071

int main(int argc, char **argv)
{
  char n;
  while(cin >> n){
    int M = 0;
    M = n - '0';
    while(cin >> n && n != '#'){
      M <<= 1;
      M += n - '0';
      M = M % MOD;
    }
    puts(M ? "NO" : "YES");
  }
  return 0;
}
