//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1408

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll n=0, L=0;

int main(){
  while(scanf("%lld %lld",&n,&L) && n && L){
    vector<ll> seq(L,0);
    for(ll i=0; i < L; i++) scanf("%lld",&seq[i]);    

    ll qt=0, it=0, r=0, ans=n-1;
    seq.push_back(1000000000000000000);
    for(ll l=0; l < seq.size()-1; l++){
      while(seq[r+1] - seq[l] + 1<= n){	
		r++;
      }      
      ans = min(ans,n-(r-l+1));
    }

    printf("%lld\n",ans);
  }

  return 0;
}