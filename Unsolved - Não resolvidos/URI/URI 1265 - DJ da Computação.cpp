#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;

long long dp[30];
int n, q;

void fill(int m){
  int i = 0;
  dp[i] = n;
  while(dp[i] <= m){
    i++;
    dp[i] = dp[i-1] + (i + 1)*pow(n, (i+1));
  }
  //printf("i foi %d\n", i);
}

long long solve(int q){
  if(q <= n){
    return q-1;
  }
  int group = 0;
  while(q > dp[group]){
    group++;
  }
  printf("solucao (q == %d) esta no grupo %d, onde tem %lld elementos.\n", q, group, dp[group]);
  int aux = q - dp[group-1];
  int subgroup = (aux-1)/(group+1);
  printf("no subgrupo %d (0 indexed)\n", subgroup);
  //agora quero saber quem eh ela no subgrupo
  int pos = aux - subgroup*(group+1);
  printf("ta na posicao %d\n", pos);
  if(pos >= n){
    printf("N EH %d vou retornar %d\n", n, pos%n);
    return (pos%n);
  }
  puts("asijd");
  return pos;
}

int main(int argc, char **argv)
{
  bool quebra = false;
  while(scanf("%d %d", &n, &q) && (n || q)){
    if(!quebra){
      quebra = true;
    }else puts("");
    vector<string> songs;
    int query[q];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++){
      string n;
      cin >> n;
      songs.push_back(n);
    }
    int hi = -1;
    for(int i = 0; i < q; i++){
      scanf("%d", &query[i]);
      hi = max(hi, query[i]);
    }
    if(n == 1){
      for(int i = 0; i < q; i++){
	cout << songs[0] << endl;
      }
      continue;
    }else fill(hi);
    /*for(int i = 0; i < 3; i++){
      printf("%lld ", dp[i]);
      }
      puts("");*/
    for(int i = 0; i < q; i++){
      cout << songs[solve(query[i])] << endl;
    }
  }
  return 0;
}

