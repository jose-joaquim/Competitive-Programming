//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2231
#include <cstdio>
 
int main() {
    int t;
    scanf("%d", &t);
 
    while (t--) {
        int n;
        scanf("%d", &n);
 
        int val[1000];
        for (int i = 0; i < n; i++)
            scanf("%d", &val[i]);
 
        int soma = 0, ans = 0;
        for (int i = 0; i < n; i++)
            if (i == n-1 || soma + val[i] < val[i+1]) {
                soma += val[i];
                ans++;
            }
 
        printf("%d\n", ans);
    }
}
