#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <iostream>

using namespace std;

int precedencia(char c){
	if(c == '^') 			 						 return 6;
	if(c == '*' || c == '/') 						 return 5;
	if(c == '+' || c == '-') 						 return 4;
	if(c == '>' || c == '<' || c == '=' || c == '#') return 3;
	if(c == '.') 									 return 2;
	if(c == '|')									 return 1;
	return 0;
}


int main()
{
	stack<char> pilx;
	stack<char> pily;
	string inf; char posf[1001]; int j = 0; char x;
	getline(cin, inf);
	for(unsigned int i = 0; i < inf.size(); i++){
		switch(inf[i]){
			case '(': pilx.push(inf[i]); break;
			case ')': x = pilx.top(); pilx.pop();
					  while(x != '('){
						 posf[j++] = x;
						 x = pilx.top();
						 pilx.pop();
					  }
					  break;
			case '|': x = pilx.top(); pilx.pop();
					  while(x != '('){
						  posf[j++] = x;
						  x = pilx.top();
						  pilx.pop();
					  }
					  pilx.push(x);
					  pilx.push(inf[i]);
					  break;
			case '.': x = pilx.top(); pilx.pop();
					  while(x != '(' && x != '|'){
						  posf[j++] = x;
						  x = pilx.top();
						  pilx.pop();
					  }
					  pilx.push(x);
					  pilx.push(inf[i]);
					  break;
			case '<':
			case '>':
			case '=':
			case '#': x = pilx.top(); pilx.pop();
					  while(x != '(' && x != '.'){
						  posf[j++] = x;
						  x = pilx.top();
						  pilx.pop();
					  }
					  pilx.push(x);
					  pilx.push(inf[i]);
					  break;
			case '-':
			case '+': x = pilx.top(); pilx.pop();
					  while(x != '(' && x != '<' && x != '>' && x != '=' && x != '#'){
						  posf[j++] = x;
						  x = pilx.top();
						  pilx.pop();
					  }
					  pilx.push(x);
					  pilx.push(inf[i]);
					  break;
			case '/':
			case '*': x = pilx.top(); pilx.pop();
					  while(x != '+' && x != '-' && x != '('){
						  posf[j++] = x;
						  x = pilx.top();
						  pilx.pop();
					  }
					  pilx.push(x);
					  pilx.push(inf[i]);
					  break;
			 case '^': x = pilx.top(); pilx.pop();
					  while(x != '/' && x != '*' && x != '('){
						  posf[j++] = x;
						  x = pilx.top();
						  pilx.pop();
					  }
					  pilx.push(x);
					  pilx.push(inf[i]);
					  break;
			default: posf[j++] = inf[i];
		}		
	}
	posf[j] = '\0';  
	printf("%s\n", posf);		
	return 0;
}

