#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

typedef pair<int, char> iC;

int cmp(const pair<int, char> &p1, const pair<int, char> &p2){
	return p1.first - p2.first;
} 

int main(int argc, char **argv)
{
	int ct;
	while(scanf("%d", &ct) != EOF){
		vector<iC> vetor;
		bool used[ct];
		int total = 0;
		memset(used, false, sizeof used);
		for(int i = 0; i < ct; i++){
			int size;
			char lado;
			cin >> size >> lado;
			vetor.push_back(make_pair(size, lado));
		}
		//sort(vetor.begin(), vetor.end(), cmp);
		for(int i = 0; i < ct; i++){
			char c;
			if(vetor[i].second == 'D'){
				c = 'E';
			}else{
				c = 'D';
			}
			for(int j = i; j < ct; j++){
				if(vetor[j].second == c && vetor[j].first == vetor[i].first && !used[j] && !used[i]){
					//printf("vetor[i] tem %d e %c || vetor[j] tem %d e %c\n", vetor[i].first, vetor[i].second, vetor[j].first, vetor[j].second);
					used[i] = true;
					used[j] = true;
					total++;
					break;
				}
				//if(vetor[j].first != vetor[i].first) break;
			}
		}
		/*for(int i = 0; i < ct; i++){
			iC search = vetor[i];
			//printf("sapatado da vez eh %d | %c\n", search.first, search.second);
			if(vetor[i].second == 'D'){
				search.second = 'E';
			}else{
				search.second = 'D';
			}
			for(int j = i; j < ct; j++){
				if(vetor[j].first == search.first && vetor[j].second == search.second && !used[j]){
					//printf("%d | %c combinou com %d | %c\n", search.first, search.second, vetor[j].first, vetor[j].second);
					used[j] = true;
					used[i] = true;
					total++;
					break;
				}
			}
			//puts("fim itrecao");
		}*/
		printf("%d\n", total);
	}
	return 0;
}



