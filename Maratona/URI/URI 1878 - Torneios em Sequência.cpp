//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1878

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int c[3];

bool has_equal(vector<int> &v) {
  sort(v.begin(), v.end());
  for (int i = 0; i+1 < (int)v.size(); i++) {
    if (v[i] == v[i+1]) {
      return true;
    }
  }
  return false;
}

int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &c[i]);
    }
    
    vector<int> values;
    bool can = false;
    if (n == 2) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          values.push_back(i*c[0] + j*c[1]);
        }
      }
    } else if (n == 3) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          for (int z = 0; z < m; z++) {
            values.push_back(i*c[0] + j*c[1] + z*c[2]);
          }
        }
      }
    }
    
    can = !has_equal(values);
    
    printf("%s\n", can ? "Lucky Denis!" : "Try again later, Denis...");
  }
}
