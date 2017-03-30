//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1029
//Obrigado a Maurício Collares, que foi quem me ajudou com a implementação e fez o código.
//Thanks to Maurício Collares who helped me with the implementation and built the code.
#include <vector>
#include <map>
#include <queue>

using namespace std;

int moves[10][2] = {{0, 1}, {1, 2}, {2, 3},
  {4, 5}, {5, 6}, {6, 7},
  {0, 4}, {1, 5}, {2, 6}, {3, 7}};

int main() {
  vector<int> input[2];
  
  for (int z = 0; z < 2; z++)
    for (int i = 0; i < 8; i++) {
      int tmp;
      scanf("%d", &tmp);
      input[z].push_back(tmp);
    }
  
  priority_queue<pair<int, vector<int> > > q;
  map<vector<int>, int> dist;
  q.emplace(0, input[0]);
  
  while (!q.empty()) {
    vector<int> v = q.top().second;
    int d = -q.top().first;
    q.pop();
    
    if (dist[v] < d) continue;
    
    for (int i = 0; i < 10; i++) {
      swap(v[moves[i][0]], v[moves[i][1]]);
      int c = v[moves[i][0]] + v[moves[i][1]];
      
      if (dist.find(v) == dist.end() || dist[v] > d + c) {
        dist[v] = d + c;
        q.emplace(-d-c, v);
      }
      
      swap(v[moves[i][0]], v[moves[i][1]]);
    }
  }
  
  printf("%d\n", dist[input[1]]);
}
