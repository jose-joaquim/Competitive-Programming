#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;
 
int main() {
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n+1; i++){
        string linha = "";
        getline(cin, linha);
        stringstream palavras(linha);
        string palavra = "";
        while(palavras >> palavra){
            cout << palavra[0];
        }
        if(i > 0){
            cout << endl;
        }
    }
 
    return 0;
}

