/*#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	int m, n, q, t;
	cin >> t;
	for(int r = 0; r < t; r++){
		cin >> m >> n >> q;
		char matriz[m][n];
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				gets(&matriz[i][j]);
				//fflush(stdin);
			}
		}		
		cout << m << " " << n << " " << q << endl;
		fflush(stdin);
		for(int k = 0; k < q; k++){
			int cl, cc, large = 1; bool continua = true; int ax, ay;
			cin >> cl >> cc;
			//cout << cl << cc;
			if(cl == 0 || cl == m-1) { puts("1"); continue; }
			if(cc == 0 || cl == n-1) { puts("1"); continue; }
			char centro = matriz[cl][cc];
			while(continua){
				ax = 1;
				ay = 1;
				printf("centro eh %c\nmatriz centro[%d][%d] eh %c\n", centro, cc, cl, matriz[cl][cc]);
				system("pause");
				if((matriz[cl][cc+ax] == matriz[cl][cc-ax]) == centro){
					ay += 2;
					for(int i = cc-ax; i < cc+ay; i++){
						if(!(matriz[cl-ax][i] == centro)){
							continua = false;
						}
					}
					if(!continua) break;
					for(int i = cc-ax; i < cc+ay; i++){
						if(!(matriz[cl+ax][i] == centro)){
							continua = false;
						}
					}
					if(!continua) break;
					large +=2;
					ax++;				
					if(cl == 0 || cl == m-1) { break; }
					if(cc == 0 || cl == n-1) { break; }
				}			
			}
			cout << large << endl;
		}
	}
	return 0;
}*/
#include <stdio.h> 
#include <stdlib.h> 
 

 int main() { 
     int T; 
     char map[102][102]; 
     int i, M, N, Q, x, y; 
     scanf("%d", &T); 
     while(T--) { 
         scanf("%d %d %d", &M, &N, &Q); 
         getchar(); 
         for(i = 0; i < M; i++) 
             gets(map[i]); 
         printf("%d %d %d\n", M, N, Q); 
         while(Q--) { 
             scanf("%d %d", &x, &y); 
             int ans = 1; 
             int i, a, b; 
             for(i = 0; i <= M || i <= N; i++) { 
                 int flag = 0; 
                 for(a = x-i; a <= x+i; a++) { 
                     for(b = y-i; b <= y+i; b++) { 
                         if(a < 0 || b < 0 || a >= M || b >= N) { 
                             flag = 1;break; 
                         } 
                         if(map[a][b] != map[x][y]) 
                             flag = 1; 
                     } 
                 } 
                 if(flag == 0) { 
                     if(ans < 2*i+1) 
                         ans = i*2+1; 
                 } else 
 					break;  
             } 
             printf("%d\n", ans); 
         } 
     } 
     return 0; 
} 


