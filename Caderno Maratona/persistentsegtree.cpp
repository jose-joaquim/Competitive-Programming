struct node{
  int val;

  node *left, *right;
  
  node(){}
  node(node *l, node *r, int v){
    left = l;
    right = r;
    val = v;
  }
};

int n, q;
int A[MAXN];
node *version[MAXN];

void build(node *n, int low, int high){
  if(low == high){
    n->val = A[low];
    return;
  }

  int mid = (low + high) >> 1;
  n->left = new node(NULL, NULL, 0);
  n->right = new node(NULL, NULL, 0);
  build(n->left, low, mid);
  build(n->right, mid + 1, high);
  n->val = n->left->val + n->right->val;
}

void upgrade(node *prev, node *cur, int low, int high, int idx, int value){
  if(idx > high || idx < low  || low > high) return;

  if(low == high){
    cur->val = value;
    return;
  }

  int mid = (low + high) >> 1;
  if(idx <= mid){
    cur->right = prev->right;
    cur->left = new node(NULL, NULL, 0);
    upgrade(prev->left,cur->left, low, mid, idx, value);
  }else{
    cur->left = prev->left;
    cur->right = new node(NULL, NULL, 0);
    upgrade(prev->right, cur->right, mid+1, high, idx, value);
  }

  cur->val = cur->left->val + cur->right->val;
}

int query(node* n, int low, int high, int l, int r){
  if (l > high || r < low || low > high) return 0;
  
  if (l <= low && high <= r) return n->val;
  
  int mid = (low+high) >> 1;
  
  int p1 = query(n->left,low,mid,l,r);
  int p2 = query(n->right,mid+1,high,l,r);
  
  return p1 + p2;
}

int main(){
  int T; scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);

    node *root = new node(NULL, NULL, 0);
    build(root, 0, n - 1);
    version[0] = root;
    int curVersion = 1;
    
    scanf("%d", &q);
    while(q--){
      int u, x, y; scanf("%d %d %d", &u, &x, &y);
      if(u == 1){
        int k; scanf("%d", &k);
        printf("%d\n", query(version[k], 0, n - 1, x - 1, y - 1)); 
      }else{
        version[curVersion] = new node(NULL, NULL, 0);
        upgrade(version[curVersion - 1], version[curVersion], 0, n - 1, x - 1, y);
        curVersion++;
      }
    }
  }
  return 0;
}
