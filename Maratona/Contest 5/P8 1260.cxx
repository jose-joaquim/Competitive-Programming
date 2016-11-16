/*#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct{
	int qtd;
	string nome;
}Tipos;

int main(int argc, char **argv)
{
	vector<string> listaNomes;
	vector<Tipos> tipos;
	int x, qtdGeral = 0; char arvore[50];
	scanf("%d", &x);
	for(int i = 0; i<x;i++){
		while(gets(arvore)){
			fflush(stdin);
			if(!listaNomes.size()){
				
			}else{
				tipos.insert
	return 0;
}
*/
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int num, total, repeat = 0;
    string tree;
    map <string, int> table;
    map <string, int>::iterator it;

    scanf("%d", &num);
    while (repeat < num + 2) {
        table.clear();
        total = 0;

        while (true) {
            getline(cin, tree);

            if (tree == "") {
                repeat++;
                break;
            }

            if (table.find(tree) == table.end())
                table[tree] = 1;
            else
                table[tree] += 1;

            total++;
        }

        if (table.size() > 0) {
            for (it = table.begin() ; it != table.end() ; it++) {
                cout << it->first << ' ';
                printf("%.4f\n", 100.0 * it->second/total);
            }
            if(repeat < num + 2)
                printf("\n");
        }
    }
    
    return 0;    
}
