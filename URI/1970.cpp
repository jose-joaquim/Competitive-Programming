#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000000

int n, k;
vector<int> size, size_aux;
vector<int> length;
int memo[1005][1005];
int used[101];

int solve(int id, int remW){
  if (id >= (int)size_aux.size()) {
    return 0;
  }

  if (remW < 0) {
    return -INF;
  }

  int &ret = memo[id][remW];

  if (ret == -1) {
    if (size_aux[id] > remW) {
      return ret = solve(id + 1, remW);
    }

    ret = max(solve(id + 1, remW), size_aux[id] + solve(id + 1, remW - size_aux[id]));
  }

  return ret;
}

vector<int> removeElementsUsed(int r, vector<int> &vet) {
  vector<int> ret;
  int i = 0;
  int remW = r;
  while (i < (int)vet.size()) {
    //printf("looking (%d, %d) = %d => col %d\n", i, remW, (int)memo[i][remW], remW - size[i]);
    if (memo[i][remW] - memo[i + 1][remW - vet[i]] == vet[i]) {
      //printf("   usei %d\n", (int)vet[i]);
      remW -= vet[i];
      i += 1;
    } else {
      //printf(" %lld != %d\n", memo[i][remW] - memo[i + 1][remW - vet[i]], vet[i]);
      ret.push_back(vet[i]);
      i += 1;
    }
  }
  return ret;
}

int main(int argc, char **argv)
{
  memset(memo, -1, sizeof memo);
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++){
    int u;
    scanf("%d", &u);
    size.push_back(u);
  }
  for(int i = 0; i < k; i++){
    int u;
    scanf("%d", &u);
    length.push_back(u);
  }
  sort(length.begin(), length.end());
  int ans = -INF;
  do{
    size_aux = size;
    int resp = 0;
    for(int i = 0; i < k; i++){
      //printf("(bolsa %d) size_aux eh: ", length[i]);
      //for (int x : size_aux) { printf("%lld ", x); } puts("");
      memset(memo, -1, sizeof memo);
      int aux = solve(0, length[i]);
      //printf("aux %lld\n", aux);
      resp += aux;

      /*for (int j = 0; j < 12; j++) {
        for (int k = 0; k < 12; k++) {
          printf("%-4d ", (int)memo[j][k]);
        }
        puts("");
      } puts("");*/
      
      size_aux = removeElementsUsed(length[i], size_aux);
      //printf("size now has %d elements\n", size.size());
    }
    ans = max(ans, resp);
    //puts("");
  }while(next_permutation(length.begin(), length.end()));
  printf("%d\n", ans);
  return 0;
}

