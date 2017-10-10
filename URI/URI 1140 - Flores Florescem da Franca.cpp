//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1140

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <string.h>

using namespace std;

int main()
{
   string line;
   getline(cin, line);
   char firstc = tolower(line[0]);

   while (firstc != '*') {
	  if(!strcmp(&firstc, " ")){
		  cout << "Y\n";
		  continue;
	  }
      stringstream s(line);
      string w;
      bool res = true;

      s >> w;
      while (s >> w) {
         char c = tolower(w[0]);
         res = (res && (c == firstc));
      }

      if (res) cout << "Y\n";
      else cout << "N\n";
      
      getline(cin, line);
      firstc = tolower(line[0]);
   }

   return 0;
}

