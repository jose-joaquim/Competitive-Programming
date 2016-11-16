#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

typedef struct c {
    int ent, sai;
}carro;

int main() {
	stack<carro> pilha;
    int n, k, a, b, tempoS;
    bool resp = false;
    scanf("%d %d", &n, &k);
    while(n != 0 && k != 0){
		carro car;
        resp = true;        
        for(int i=0; i<n; i++){
			tempoS = 0;
            scanf("%d %d", &a, &b);                       
            while(pilha.size() > 0 && a>=pilha.top().sai){
                resp &= pilha.top().sai >= tempoS;
                tempoS = pilha.top().sai;
                pilha.pop();
            }            
            resp &= pilha.size() < (unsigned)k;
            car.ent = a; car.sai = b;
            pilha.push(car);
        }        
        tempoS = 0;
        while(pilha.size() > 0){
            resp &= pilha.top().sai >= tempoS;
            tempoS = pilha.top().sai;
            pilha.pop();
        }        
        if(resp) puts("Sim");
			else puts("Nao");			
		scanf("%d %d", &n, &k);
    }
    return 0;
}

