//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1838

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
 
#define INF 1000000000
 
using namespace std;
 
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
int main(int argc, char **argv)
{
    int ct;
    scanf("%d", &ct);
    vector<ii> num;
    for(int i = 0; i < ct; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        num.push_back(ii(u, v));
    }
    vector<vii> AdjList(ct+2, vii());
    for(int i = 0; i < ct; i++){
        for(int j = 0; j < ct; j++){
            if(num[j].first >= num[i].second){
                AdjList[i].push_back(ii(j, num[j].first - num[i].second));
            }
        }
    }
    for(int i = 0; i < ct; i++){//source
        AdjList[i].push_back(ii(ct, 3600-num[i].second));
    }
    for(int i = 0; i < ct; i++){//source
        AdjList[ct+1].push_back(ii(i, num[i].first - 1));
    }
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    vector<int> dist(ct+2, INF);
    pq.push(ii(0, ct+1)); dist[ct+1] = 0;
    while(!pq.empty()){
        ii front = pq.top(); pq.pop();
        int d = front.first; int u = front.second;
        if(d > dist[u]) continue;
        for(int j = 0; j < (int) AdjList[u].size(); j++){
            ii v = AdjList[u][j];
            if(dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    /*for(int i = 0; i < ct+2; i++){
        printf("%d ", dist[i]);
    }*/
    printf("%d\n", 3600 - dist[ct]-1);
    return 0;
}
