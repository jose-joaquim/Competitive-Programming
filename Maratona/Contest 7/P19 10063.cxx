#include <iostream>
#include <cstdio>

using namespace std;

string str;

void gen(int index,string Q)
{
    if(index==str.size())
    {
        cout<<Q<<"\n";
        return ;
    }
    else
    {
        char C= str[index];
        string w;
        for(int i=0; i<=Q.size(); i++)
        {
            w=Q;
            w.insert(w.begin()+i,C);
            gen(index +1 , w);
        }
    }
    return ;
}


int main(int argc, char **argv)
{
	bool check = false;
	string r;
 
    while(cin>>str)
    {
        r="";
        if (check)
            printf("\n");
        else
            check = true;
         r+=str[0];
        gen(1,r);
    }
	return 0;
}

