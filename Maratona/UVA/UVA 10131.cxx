#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef struct Ex{
	pair<int, int> A;
	int id;
}elefante;

bool cmp(const elefante &a, const elefante &b){
	 if(a.A.first != b.A.first)
        return a.A.first < b.A.first;
	return a.A.second > b.A.second;
}

vector<int> length;
vector<int> sol;

int main(int argc, char **argv)
{
	int a, b, n = 0;
	int LIS = 0;
	elefante E[1000];
	while(scanf("%d %d", &a, &b) != EOF){
		E[n].A = make_pair(a, b);
		E[n].id = n+1;
		n++;
	}
	sort(E, E+n, cmp);
	length.assign(n, 1);
	int ans[n];
	/*for(int i = 0; i < n; i++){
		printf("%d %d\n", E[i].A.first, E[i].A.second);	
	}*/
	
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < i ; j++){
			if(E[j].A.first < E[i].A.first && E[j].A.second > E[i].A.second){
				//puts("oi");
				length[i] = length[j] + 1;
			}
			if(length[i] > LIS){
				LIS = length[i];
			}
		}
	}
	/*for(int i = 0; i < (int) length.size(); i++) printf("%d ", length[i]);
	puts("");*/
	int pos = 0;
	for(int i = 0; i < n; i++) if(length[i] > length[pos]) pos = i;
	LIS = length[pos];
	printf("%d\n", LIS);
	int top = length[pos] - 1;
	ans[top] = E[pos].id;
	
	for(int j = pos - 1; j >=0; j--){
        if(length[j] == length[pos] - 1 && E[j].A.first < E[pos].A.first && E[j].A.second > E[pos].A.second) {
            ans[--top] = E[j].id;
            pos = j;
        }
	}
	
	for( int i = 0; i < LIS; i++)printf("%d\n", ans[i]);
	/*for(int i = n - 1; i >= 0; i--){
		//puts("oi");
		if(length[i] == LIS){
			sol.push_back(E[i].id);
			LIS--;
		}
	}
	for(int i = 0; i < (int) sol.size(); i++) printf("%d ", sol[i]);
	puts("");*/
	return 0;
}

