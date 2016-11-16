#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

#define INF 1000000000

using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
int E;

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &E);
	AdjList.assign(E, vi());
	for(int i = 0; i < E; i++){
		int num, k;
		cin >> num;
		for(int j = 0; j < num; j++){
			cin >> k;
			AdjList[i].push_back(k);
		}
	}
	cin >> ct;
	for(int i = 0; i < ct; i++){
		//int mAux = 0;
		int M = 0, D = 0, day = 1;
		int s;
		scanf("%d", &s);
		queue<int> q;
		vi dist(E, INF); 
		vi dia(E, 0);
		q.push(s); dist[s] = 0;
		while(!q.empty()){
			day++;
			int u = q.front(); q.pop();
			for(int j = 0; j < (int) AdjList[u].size(); j++){
				int v = AdjList[u][j];
				if(dist[v] == INF){//esse vertice nao foi visitado
					//printf("vertice %d nao sabe, quem ta contando eh %d\n", v, u);
					q.push(v);
					//mAux++;
					dist[v] = dist[u]+1;
					dia[dist[v]]++;
				}else{
					//printf("vertice %d JA SABE quem ia contar era %d\n", v, u);
				}
			}
			//puts("acabou dia");
			/*if(mAux > M){
				M = mAux;
				D = day;
			}
			mAux = 0;*/
		}
		//if(M == 0) printf("0\n"); 
		//else{
			for(int i = 0; i < E; i++){
				if(dia[i] > M){
					M = dia[i];
					D = i;
				}
			}
			M == 0 ? printf("0\n") : printf("%d %d\n", M, D);
		//}
	}
	return 0;
}

