#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef vector<int> vi;

int n=0, e=0;
vi w;

char seq[100010];
int mark[100010];
int dist[100010];
bool visited[10];

int BFS(int i){
	queue<int> fila;
	fila.push(i);
	mark[i]=1;
	
	while(!fila.empty()){
		
		int v = fila.front(); 
		fila.pop();		
		if (v == (int) w.size() - 1) return dist[v];
		
		if (!visited[w[v]]) {
			visited[w[v]] = 1;
			for(int q=0; q < (int)w.size(); q++) {
				if (w[q] == w[v]){
					int ind = q;			
					if (!mark[ind]){
						mark[ind]=1;
						fila.push(ind);
						dist[ind] = dist[v]+1;
					}
				}
			}
		}
		
		if( v-1 >= 0 && !mark[v-1]){
			mark[v-1]=1;
			fila.push(v-1);
			dist[v-1] = dist[v] + 1;
		}
		
		if( v+1 < n && !mark[v+1]){
			mark[v+1]=1;
			fila.push(v+1);
			dist[v+1] = dist[v] + 1;
		}
			
	}	
	
	return dist[n-1];
}

int main(int argc, char **argv)
{	
	scanf("%s",seq);
	n = strlen(seq);
	
	memset(visited, false, sizeof visited);
	memset(dist,0,sizeof dist);
	memset(mark,0,sizeof mark);
	
	for(int i = 0; i < n; i++){
	  w.push_back(seq[i] - '0');
	}	
	
	printf("%d\n", BFS(0));
	
	return 0;
}

