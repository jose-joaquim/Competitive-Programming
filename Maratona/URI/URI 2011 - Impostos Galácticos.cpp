//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2011


#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
#include <math.h>

#define INF 10000000000
#define EPS 1e-10

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef pair<double, int> di;
int N, M;
vector<viii> AdjList;

double dijkstra(double t){
  //printf("t eh %lf\n", t);
  priority_queue<di, vector<di>, greater<di> > pq;
  pq.push(di(0.0, 1));
  vector<double> dist(N+1, INF); dist[1] = 0.0;
  while(!pq.empty()){
    di front = pq.top(); pq.pop();
    double d = front.first; int u = front.second;
    if(d > dist[u]) continue;
    for(int j = 0; j < (int) AdjList[u].size(); j++){
      iii v = AdjList[u][j];
      double A = v.second.first, B = v.second.second;
      double weight = (A*1.0)*t + (1.0*B);
      if(dist[u] + weight < dist[v.first]){
		dist[v.first] = dist[u] + weight;
		pq.push(di(dist[v.first], v.first));
      }
    }
  }
  return dist[N];
}

double f(double t){
  return dijkstra(t);
}

double ternarySearch(){
  double right = 1440.0, left = 0.0, leftThird, rightThird;
  while(true){
    if(fabs(right - left) < EPS){
      break;
    }

    leftThird = left + (right - left)/3.0;
    rightThird = right - (right - left)/3.0;

    if(dijkstra(leftThird) < dijkstra(rightThird)){
      left = leftThird;
    }else right = rightThird;
    
  }
  return (left + right)/2.0;
}


int main(){
  while(scanf("%d %d", &N, &M) != EOF){
    AdjList.assign(N+1, viii());
    for(int i = 0; i < M; i++){
      int u, v, A, B;
      cin >> u >> v >> A >> B;
      AdjList[u].push_back(iii(v, ii(A, B)));
      AdjList[v].push_back(iii(u, ii(A, B)));
    }
    printf("%0.5lf\n", f(ternarySearch()));
  }
  return 0;
}
