#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

set<ii> pairs;
set<ll> values;

// Override comparator
iterator::set<ii> NodePairs(in i) {
  return;
}

iterator::set<ll> NodeValues(ll value) {
  return;
}

ll maxValue() {
  return;
}

int main(){
  int n; scanf("%d", &n);
  int sum[n+1];
  sum[0] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &sum[i+1]);
    sum[i+1] += sum[i];
  }

  pairs.insert(ii(0, n));
  values.insert(sum[n]);

  for (int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    x -= 1;
    printf("%lld\n", maxValue());

    auto nodePair = NodePairs(x);
    auto nodeLeft = ii(nodePair->left, x);
    auto nodeRight = ii(x+1, nodePair->right);

    auto nodeValues = NodeValues(sum[nodePair->right] - sum[nodePair->left-1]);
    values.remove(nodeValues);

    pairs.remove(nodePair);
    pairs.insert(nodeLeft);
    pairs.insert(nodeRight);

    ll valueLeft = sum[nodeLeft->right] - sum[nodeLeft->left - 1];
    ll valueRight = sum[nodeRight->right] - sum[nodeRight->left - 1];
    values.insert(valueLeft);
    values.insert(valueRight);
  }

  puts("");
}
