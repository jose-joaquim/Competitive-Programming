#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n, m, a, b;
vector<vi> AdjList;
vi ga, gb;
vi pnode;
vector<bool> mark;

int contav(){
  int tv = n;
  bool cont = 1;
  while(tv > 0 && cont){
    cont = false;
    for(int i = 1; i <= n; i++){
      if(mark[i] && ga[i] >= a && (tv - ga[i] - 1 >= b)){
	continue;
      }else{
	if(mark[i]){
	  tv--;
	  for(int j = 0; j < (int) AdjList[i].size(); j++) ga[AdjList[i][j]]--;
	  mark[i] = false;
	  cont = true;
	}
      }
    }   
  }
  return tv;
}

int main(){
  cin >> n >> m >> a >> b;
  AdjList.assign(n + 1, vi());
  ga.assign(n + 1, 0);
  gb.assign(n + 1, 0);
  mark.assign(n + 1, true);
  for(int i = 0; i < m; i++){
    int x = 0, y = 0;
    cin >> x >> y;
    AdjList[x].push_back(y);
    AdjList[y].push_back(x);
    ga[x]++, ga[y]++;
  }
  printf("%d\n", contav()); 
  return 0;
}
