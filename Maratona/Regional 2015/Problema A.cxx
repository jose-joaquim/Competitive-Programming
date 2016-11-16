#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

const int QT = 10005;
vector<int> adj[QT];
vector<int> adj2[QT];
bool visited[QT] = {false};
int weight[QT][QT];
int weight2[QT][QT];

void init() {
  for (int i = 0; i < QT; i++) {
    adj[i].clear();
    adj2[i].clear();
  }
}

void change_graph() {
  for (int i = 0; i < QT; i++) {
    int u = i;
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j];
      int p1 = weight[u][v];
      for (int z = 0; z < adj[v].size(); z++) {
        int h = adj[v][z];
        int p2 = weigth[v][z];
        if (u == h) {
          continue;
        }
        adj2[u].push_back(h);
        weight2[u][h] = p1 + p2;
      }
    }
  }
}


int main() {
  init();
}
