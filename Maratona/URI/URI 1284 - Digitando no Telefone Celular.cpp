//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1284
#include <iomanip>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <bitset>

using namespace std;

const int MAX_N = 100010;

struct node{
  bool end;
  bitset<26> cnt;
  struct node *link[26];
  node(){
    end = false;
    for(auto &p : link) p = nullptr;
  }
};

typedef struct arvore{
  vector<node *> limpar;
  int nodes;
  node *root;
  
  arvore(vector<string> &dic){
    nodes = 0;
    limpar.clear();
    root = new node();
    for(auto &word : dic){
      addWord(root, word, 0);
    }
  }

  ~arvore(){
    for(int i = 0; i < (int) limpar.size(); i++){
      delete limpar[i];
    }
    delete root;
  }

  void addWord(node *x, string &j, int pos){
    if(pos == j.size()){
      x->end = true;
    }else{
      int L = j[pos] - 'a';
      if(x->link[L] == nullptr){
        x->cnt.set(L);
        node *nova = new node();
        limpar.push_back(nova);
        x->link[L] = nova;
      }
      addWord(x->link[L], j, pos + 1);
    }
  }

  double countType(){
    typedef pair<node *, int > ni;
    int ans = 0;
    queue<ni> q;
    for(int i = 0; i < 26; i++){
      if(root->link[i] != nullptr){
        q.push(ni(root->link[i], 1));
      }
    }
    while(!q.empty()){
      ni top = q.front(); q.pop();
      node *no = top.first; int dig = top.second;
      bool addMore = no->cnt.count() > 1;
      bool vai = no->cnt.count() == 1;
      bool finish  = (no->cnt.count() == 0);
      if(no->end && finish){
        ans += dig;
        continue;
      }else if(no->end){
        ans += dig;
        addMore = true;
      }
      for(int i = 0; i < 26; i++){
        if(no->link[i] != nullptr){
          q.push(ni(no->link[i], dig + addMore));
        }
      }
    }

    return (double)ans;
  }
}Trie;

int n;
vector<string> arr;

inline void clean(){
  arr.clear();
}

inline void readInput(){
  arr.resize(n);
  for(auto &w : arr)
    cin >> w;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  while(cin >> n){
    cout << fixed << showpoint;
    cout << setprecision(2);
    clean();
    readInput();
    Trie *tree = new Trie(arr);
    cout << tree->countType()/n << '\n';
    delete tree;
  }
  return 0;
}
