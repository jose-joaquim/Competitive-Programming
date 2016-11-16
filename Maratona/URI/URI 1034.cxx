#include <iostream>
#include <cstdio>

using namespace std;

int num_moedas(int N, int M, int * m) {
    int dp[N+1];

    dp[0] = 0;

    for(int i=1; i<=N; i++) {
        dp[i] = 1000000;

        for(int j=0; j<M; j++) {
            if(i-m[j] >= 0) {
                dp[i] = min(dp[i], dp[ i-m[j] ]+1);
            }
        }
    }

    return dp[N];
}

int main(){
	int ct;
	scanf("%d", &ct);
	for(int q = 0; q < ct; q++){
		int coins[26];
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++){
			scanf("%d", &coins[i]);
		}
		printf("%d\n", num_moedas(m, n, coins));
	}
	return 0;
}
