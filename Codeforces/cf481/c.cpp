#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int n, m;

int main() {
  cin >> n >> m;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll room = 0;
  ll room_sum = 0;
  ll room_upper = arr[0];
  for (int i = 0; i < m; i++) {
    ll x; cin >> x;

    while(room_upper < x) {
      room_sum += arr[room];
      room++;
      room_upper += arr[room];
      //printf("vim para o quarto %lld\n", room);
    }

    //printf("         x %lld room_sum %lld\n", x, room_sum);
    //printf("         estou no quarto %lld, room_upper eh %lld\n", room, room_upper);

    ll wh = -1;
    if (room != 0) {
      wh = x - room_sum;
    } else {
      wh = x;
    }
    
    cout << room + 1 << " " << wh << '\n';
  }
  return 0;
}
