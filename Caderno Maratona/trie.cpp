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
}Trie;
