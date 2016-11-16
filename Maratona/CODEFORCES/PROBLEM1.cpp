#include <bits/stdc++.h>

using namespace std;

int main(){
  char vet[105];
  while(scanf("%s", vet) != EOF){
    int ans = 0;
    int p = 0;
    int at = 1;
    char last = 'a', current = 'a';
    for(int i = 0; vet[i] != '\0'; i++){
      int op1, op2 = 0;
      op1 = op2;
      if(vet[i] > current){
	op1 = vet[i] - current;
	op2 = current - 'a' + 'z' - vet[i] + 1;
	ans += min(op1, op2);
	current = vet[i];
      }else if(vet[i] < current){
	op1 = current - vet[i];
	op2 = 'z' - current + 1 + vet[i] - 'a';
	ans += min(op1, op2);
	current = vet[i];
      }else{
	current = vet[i];
      }
      /*p = vet[i] - '0';
      if( at != p){
	int op1 = fabs(p - at);
	int op2 = fabs((at + 26) - p);
	if (op1 < op2){
	  ans += op1;
	}else{
	  ans += op2;
	}
	at = p;
      }*/
    }
    printf("%d\n",ans);
  }
  return 0;
}
