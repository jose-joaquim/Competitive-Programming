#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
//#include <windows.h>
#include <cstring>

using namespace std;

long long ans = 0;
int m;
vector<string> aux;

void junta(int left, int right, vector<string> &r){ // tentando intercalar	
	int mid = (left + right)/2;	
	int i = left, j = mid+1; //duas metades, i controla a esquerda e j a direita
	int k = 0; //vai controlar as posições do vetor auxiliar
	//puts("comecei intercalar");
	while(i <= mid && j <= right){
		if(r[i] <= r[j]){ //o número da esquerda é menor do que o da direita
			aux[k++] = r[i++]; //i++ pra eu ir olhar a prox posição do r[i]
		}else{
			aux[k++] = r[j++];
			ans += (mid - i)+1;			
		}
	}	
	while(i <= mid){
		aux[k++] = r[i++];
	}
	while(j <= right){
		aux[k++] = r[j++];
	}
	for(int i = left; i <= right; i++){
		 r[i] = aux[i-left];
	}
	//puts("");
}

void mergesort(int left, int right, vector<string> &r){	
	//Sleep(100);
	if(left < right){
		int mid = (left + right)/2;
		//printf("left %d | right %d | mid %d\n", left, right, mid);
		mergesort(left, mid, r);
		mergesort(mid+1, right, r);
		junta(left, right, r);
	}	
}

int main(int argc, char **argv)
{	
	while(cin >> m){
		ans = 0;
		vector<string> mat;
		for(int i = 0; i < m; i++){
			string matricula;
			cin >> matricula;
			mat.push_back(matricula);
		}
		aux.resize(mat.size());
		mergesort(0, mat.size()-1, mat);
		//for(int i = 0; i <(int)mat.size();i++) cout << mat[i] << " ";
		//puts("");
		cout << ans << endl;
	}
	return 0;
}


