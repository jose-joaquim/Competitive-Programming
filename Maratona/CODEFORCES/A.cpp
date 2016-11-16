#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
  char op[10], op2[10], op1[10];
  op1[2] = op2[2] = '\0';
  scanf("%s\n", op);
  scanf("%c%c:%c%c", &op1[0], &op1[1], &op2[0], &op2[1]);
  // printf("op1: %s | op2: %s\n", op1, op2);
  if(op[0] == '1'){
    if(op1[0] > '1'){
      if(op1[1] >= '1'){
	op1[0] = '0';
      }else{
	op1[0] = '1';
      }
    }else if(op1[0] == '0'){
      if(op1[1] == '0')  op1[1] = '1';
    }else{
      if(op1[1] > '2') op1[1]  = '0';
    }
    if(op2[0] > '5') op2[0] = '0';
  }else{
    if(op1[0] > '2') op1[0] = '0';
    else if(op1[1] > '3' && op1[0] == '2') op1[1] = '2';

    if(op2[0] > '5') op2[0] = '5';
  }
  printf("%s:%s\n", op1, op2);
}
