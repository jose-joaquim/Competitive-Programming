#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
map<int, vi> map_AdjList;
map<int, int> in_degree;
map<int, int> out_degree;
int k, w;

void dfs(int u){
  
}

int main(){
  while(scanf("%d %d", &k, &w) && (k || w)){
    if(w == 0){
      puts("Y");
      continue;
    }
    bool go = true;
    int criancas = 1;
    //AdjList.assign(k, vi());
    for(int i = 0; i < w; i++){
      int u, v;
      scanf("%d %d", &u, &v);
      if(!long_int.count(u)){
        long_int[u] = criancas;
	out_degree[long_int[u]] = 0;
	in_degree[long_int[u]] = 0;
	criancas++;
      }
      if(!long_int.count(v)){
	long_int[v] = criancas;
	in_degree[long_int[v]] = 0;
	out_degree[long_int[v]] = 0;
	criancas++;
      }
      AdjList[long_int[u]].push_back(long_int[v]);
      out_degree[long_int[u]]++;
      in_degree[long_int[v]]++;
    }
    if(!go){
      puts("N");
      break;
    }
    puts("oi");
  }
  return 0;
}
