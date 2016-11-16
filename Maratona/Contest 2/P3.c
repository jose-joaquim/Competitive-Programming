#include <stdio.h>
#define min(a,b) (a<b)?a:b;
#define max(a,b) (a>b)?a:b;
int main()
{
    char s[6];
    int n,min,max;
    min = 0;
    max = 11;
    while(scanf("%d %s %s",&n,s,s)==3)
    {
        if(s[0]=='o')
        {
            if(n>min&&n<max)
                puts("Stan may be honest");
            else
                puts("Stan is dishonest");
            min = 0;
            max = 11;
        }
        else if(s[0]=='l'){
            min = max(min,n);}
        else if(s[0]=='h'){
            max = min(max,n);}
    }
    return 0;
}

