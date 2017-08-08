//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/2087
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct node{
  struct node *link[26];
  bool end;
};

int n, nos;
bool ans;

vector<node *> limpar;

inline void initialize(node *x){
  x->end = false;
  for(auto &v : x->link) v = nullptr;
}

void addWord(node *x, string &j, int pos){
  if(x->end){//se eu cheguei em uma folha e a minha string n acabou
    ans = false;
  }else{
    if(pos == j.size()){
      x->end = true;
    }else{
      int L = j[pos] - 'a';
      if(x->link[L] == nullptr){
        node *nova = (node *) malloc(sizeof(node));
        limpar.push_back(nova);
        x->link[L] = nova;
        initialize(x->link[L]);
      }
      addWord(x->link[L], j, pos + 1);
    }
  }
}

bool buildTrie(vector<string> &arr){
  node root;
  initialize(&root);
  for(int i = 0; i < n; i++){
    addWord(&root, arr[i], 0);
  }
  return ans;
}

void clean(){
  for(int i = 0; i < (int) limpar.size(); i++){
    free(limpar[i]);
  }
  limpar.clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  while((cin >> n) && n){
    ans = true;
    vector<string> arr(n);
    for(auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    cout << (buildTrie(arr) ? "Conjunto Bom" : "Conjunto Ruim") << '\n';
    clean();
  }
  return 0;
}
