//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2830
#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int s, t;

bool isPrime(int number){
  bool ret = true;
  for(int i = 2; i * i <= number; i++){
    if(number % i == 0) return false;
  }
  return true;
}

int bfs(){
  queue<ii> q; q.push(ii(s, 0));
  bool visited[2000];
  memset(visited, false, sizeof visited);
  while(!q.empty()){
    ii state = q.front(); q.pop();
    int number = state.first, d = state.second;

    if(number == t)
      return d;

    int aux = number;
    vector<int> factors;
    for(int i = 2; i * i <= aux; i++){
      bool add = false;
      while(number % i == 0){
        if(!add){
          factors.push_back(i);
          add = true;
        }
        number /= i;
      }
    }
    if(number != 1) factors.push_back(number);
    for(int k = 0; k < (int) factors.size(); k++){
      if(aux == factors[k] || factors[k] == 1) continue;
      if(!visited[aux + factors[k]] && aux + factors[k] <= t){
        visited[aux + factors[k]] = true;
        q.push(ii(aux + factors[k], d + 1));
      }
    }
  }

  return -1;
}

int main(){
  int cs = 0;
  while(scanf("%d %d", &s, &t) && s){
    printf("Case %d: ", ++cs);
    printf("%d\n", bfs());
  }
  return 0;
}
