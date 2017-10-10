void monta_arvore(int u, int p, int l) {
  pai[u] = p;
  nivel[u] = l;
    
  if(l > maxNivel) {
    maxNivel = l;
  }

  for(int i=0; i<(int)AdjList[u].size(); i++) {
    int v = AdjList[u][i];

    if(!pai[v]) {
      monta_arvore(v, u, l+1);
    }
  }
}

void monta_super_pai(int u, int p) {
  super_pai[u] = p;

  if(nivel[u]%segmento == 0) {
    p = u;
  }

  for(int i=0; i<(int)AdjList[u].size(); i++) {
    int v = AdjList[u][i];

    if(!super_pai[v]) {
      monta_super_pai(v, p);
    }
  }
}

int LCA(int a, int b) {
  while(super_pai[a] != super_pai[b]) {
    if(nivel[a] > nivel[b]) {
      a = super_pai[a];
    } else {
      b = super_pai[b];
    }
  }
  while(a != b) {
    if(nivel[a] > nivel[b]) {
      a = pai[a];
    } else {
      b = pai[b];
    }
  }
  return a;
}

monta_arvore(1, 1, 0);
segmento = sqrt(maxNivel);
monta_super_pai(1, 1);
int a = pos[i][0];
int b = pos[i][1];
int c = LCA(a, b);		
ans += (nivel[a] - nivel[c]) + (nivel[b] - nivel[c]);
