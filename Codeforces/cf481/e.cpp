#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

long long read(){
  char c;while(c=getchar(),(c<'0'||c>'9')&&c!='-');
  long long x=0,y=1;c=='-'?y=-1:x=c-'0';
  while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';
  return x*y;
}

const int Maxn=1e5+5;
long long N,M,Mi,Mx,U,L,R;

int main()
{
  N=read(),M=read();
  for(int i=1;i<=N;i++){
    long long x=read();
    Mi=min(U+=x,Mi),Mx=max(U,Mx);
  }
  L=-Mi,R=M-Mx;
  printf("%lld %lld\n", L, R);
  if(L>R)puts("0");
  else printf("%lld\n",R-L+1);
  return 0;
}

/*
  using namespace std;

  int main() {
  #ifndef PC
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #endif
  
  int n, w; cin >> n >> w;
  int ans = w, sum = w;
  for (int i = 0; i < n; i++) {
  int u; cin >> u;
  if (u > 0) {
  ans -= u;
  }
  else {
  ans += u;
  }
sum += u;

if (sum < 0) {
  cout << 0 << '\n';
  return 0;
 }
}

cout << ans + 1 << '\n';
return 0;
}
*/
