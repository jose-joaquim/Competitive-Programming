#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> vetor_pesos;

int a, b, c;

int sum(int ini, int fim){
  int soma = 0;
  for(int i = ini; i < fim; i++){
    soma += vetor_pesos[i];		
  }
  return soma;
}

bool can(int peso_permitido){
  int caminhoes = b; //b é o número de caminhões
  int k = 1;
  int peso = 0;
	
  for(int i = 0; i < a; i++)
    if(vetor_pesos[i] > peso_permitido) return false;
		
  for(int i = 0; i < a; i++){ // a é a quantidade de pesos que a gente colocou.
    // só pra não ficar vetor.size() toda hora
    if((peso + vetor_pesos[i] > peso_permitido)){//peso_permitido = X                
      k++; //passou pro próximo caminhão
      peso = vetor_pesos[i];
    }else{
      peso += vetor_pesos[i];
    }
    if(k > caminhoes){
      return false;
    }
  }
  return true;
}

int achaX(){
  int ini = 1, fim = 1e9;
  int X;
  int resposta;
  while(ini <= fim){
    X = (ini+fim)/2;		
    if(can(X)){
      resposta = X;
      fim = X-1;
    }else{
      ini = X+1;
    }	
  }	
  return resposta; 
}

int main(){
  int ct;
  cin >> ct;
  while(ct--){
    cin >> a >> b >> c;
    vetor_pesos.resize(a);
    for(int i = 0; i < a; i++){
      cin >> vetor_pesos[i];
    }		
    if(b == 1){
      int resp = sum(0, a);
      printf("%d $%d\n", resp, resp*c);
    }else{
      int xxxx = achaX();
      printf("%d $%d\n", xxxx, xxxx*c*b);
    }
  }
  return 0;
}
