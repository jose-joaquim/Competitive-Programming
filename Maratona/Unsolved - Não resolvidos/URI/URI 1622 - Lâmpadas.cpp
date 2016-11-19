#include <iostream>
#include <cstdio>

using namespace std;

void troca(string &aux, int pos){
	if(aux[pos] == 'x'){
		aux[pos] = 'o';
	}else aux[pos] = 'x';
}

int main(int argc, char **argv)
{
	int N, Q;
	while(scanf("%d %d", &N, &Q) && (N || Q)){
		string lamp;
		cin >> lamp;
		fflush(stdin);
		for(int i = 0; i < Q; i++){
			string aux = lamp;
			int k, m;
			cin >> k >> m;
			troca(aux, 0);
			int pos = 0;
			m = m%(2*N);
			while(--m){
				pos += k;
				while(pos > N) pos = pos % N;		
				troca(aux, pos);
				//cout << "AUX EH " << aux << endl;
			}		
			cout << aux << endl;
		}
	}
	return 0;
}

