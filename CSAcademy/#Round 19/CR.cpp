#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int main(){
  int n, x, k; long long ans = -1;
  int maxDir = -1000000007, maxEsq = 1000000007;
  cin >> n >> x >> k;
  unordered_map<int, ll> cities, gainMyLeft, gainMyRight;
  for(int i = 0; i < n; i++){
    int u, v; cin >> u >> v;
    maxEsq = min(maxEsq, u);
    maxDir = max(maxDir, u);
    cities[u] = v;
  }
  maxEsq = abs(min(x, maxEsq));
  x += maxEsq;
  int arr[maxEsq + maxDir + 200];
  memset(arr, 0, sizeof arr);
  for(auto p = cities.begin(); p != cities.end(); p++){
    arr[p->first + maxEsq] = p->second;
  }
  
  ll sumLeft = 0;
  for(ll i = x; i >= x - k && i >= 0; i--){
    sumLeft += arr[i];
    gainMyLeft[i] = sumLeft;
  }
  
  ll gainAteAqui = 0;
  for(ll i = x; i <= x + k && (i < maxEsq + maxDir + 200); i++){
    gainAteAqui += arr[i];
    ll gastoAteAqui = i - x;   
    ll remainGasosaVoltando = k - gastoAteAqui;
    if(i - remainGasosaVoltando >= 0){
      ll gainSeVoltasse = gainAteAqui + gainMyLeft[i - remainGasosaVoltando];
      ans = max(ans, max(gainAteAqui, gainSeVoltasse));
    }else ans = max(ans, gainAteAqui);
  }
  
  ll sumRight = 0;
  for(int i = x; i <= x + k && (i < maxEsq + maxDir + 200); i++){
    sumRight += arr[i];
    //printf("somei %d indo para a minha direita posicao %d\n", arr[i], i);
    gainMyRight[i] = sumRight;
  }
  ll gainUntilNow = 0;
  for(int i = x; i >= x - k && i >= 0; i--){
    gainUntilNow += arr[i];
    int gastoAteAqui = x - i;
    int remainGasosaVoltando = k - gastoAteAqui;
    if(gainMyRight.find(i + remainGasosaVoltando) != gainMyRight.end()){
      ll gainSeVoltasse = gainUntilNow + gainMyRight[i + remainGasosaVoltando];
      ans = max(ans, max(gainUntilNow, gainSeVoltasse));
    }else ans = max(ans, gainUntilNow);
  }
  
  printf("%lld\n", ans);
  return 0;
}
