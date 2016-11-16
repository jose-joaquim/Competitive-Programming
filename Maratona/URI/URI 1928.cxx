#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define UNVISITED -1

using namespace std;

const int MAX_N = 50000 + 10;

typedef vector<int> vi;

vector<vi> AdjList, pos;
int n, pai[MAX_N], nivel[MAX_N], vet[MAX_N], super_pai[MAX_N], marked[MAX_N];
int maxNivel = 0, segmento;

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

int main(int argc, char **argv)
{
	scanf("%d", &n);
	AdjList.assign(n+1, vi());
	pos.assign(n+1, vi());
	for(int i = 1; i <= n; i++){
		cin >> vet[i];
		pos[vet[i]].push_back(i);
	}
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
	}
	monta_arvore(1, 1, 0);
	segmento = sqrt(maxNivel);
	monta_super_pai(1, 1);
	int ans = 0;
	for(int i = 1; i <= n/2; i++){
		int a = pos[i][0];
		int b = pos[i][1];
		int c = LCA(a, b);
		
		ans += (nivel[a] - nivel[c]) + (nivel[b] - nivel[c]);
	}
	printf("%d\n", ans);
	return 0;
}

