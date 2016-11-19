#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct aq{
	int a, b, c, d;
}plano;

typedef struct cq{
	int x, y, z;
}planeta;

bool isInPlano(plano &po, planeta &pa){
	int aux = (po.a*pa.x + po.b*pa.y + po.c*pa.z);
	printf("%d e %d\n", aux, po.d);
	if(aux == po.d) return true; 
	return false;
}

int main(int argc, char **argv)
{
	int m, n;
	scanf("%d %d", &m, &n);
	vector<plano> planos(m);
	vector<planeta> planetas(n);
	for(int i = 0; i < m; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		planos[i].a = a;
		planos[i].b = b;
		planos[i].c = c;
		planos[i].d = d;
	}
	for(int i = 0; i < n; i++){
		int x, y, z;
		cin >> x >> y >> z;
		planetas[i].x = x;
		planetas[i].y = y;
		planetas[i].z = z;
	}
	for(int i = 0; i < n; i++){
		/*if(*/isInPlano(planos[0], planetas[i]);//)
			//printf("%d esta no plano\n", i);
	}
	return 0;
}

