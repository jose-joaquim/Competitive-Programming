#include <bits/stdc++.h>

using namespace std;

int ver(char i){
  return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'y';
}

int main(){
  int n;
  scanf("%d", &n);
  
  int vet[n+1];
  for(int i = 0; i < n; i++)
    scanf("%d", &vet[i]);
  getchar();
      
  bool tem = true;
  for(int i = 0; i < n; i++){
    char c;
    int j = 0;
    
    while((c = getchar()) != '\n')
      j += ver(c);

    if (j != vet[i]) {
      tem = false;
      break;
    }
  }
	
  puts(tem ? "YES" : "NO");

}
