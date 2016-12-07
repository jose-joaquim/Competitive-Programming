//Author/Autor: José Joaquim de Andrade Neto
//Link da questão: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2353

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main(int argc, char **argv)
{
	int ct;
	scanf("%d", &ct);
	while(ct--){
		int dol;
		int w, h;
		scanf("%d\n", &dol);
		vector<pair<int, int> > A;
		for(int i = 0; i < dol; i++){
			scanf("%d %d", &w, &h);
			A.push_back(make_pair(w, h));
		}
		sort(A.begin(), A.end(), cmp);
		int LIS = 0;
		int lo[dol];
		for(int i = 0; i < dol; i++){
			int pos = upper_bound(lo, lo+LIS, A[i].second) - lo;
			lo[pos] = A[i].second;
			if(pos + 1 > LIS) LIS = pos + 1;
		}
		printf("%d\n", LIS);
	}
	return 0;
}

/*#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
  if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
 
int main(){
  int ct;
  scanf("%d", &ct);
  for(int pqp=0; pqp < ct;pqp++){
    int dol;
    int w, h;
    scanf("%d\n", &dol);
    vector<pair<int, int> > A;
    for(int i = 0; i < dol; i++){
      scanf("%d %d", &w, &h);
      A.push_back(make_pair(w, h));
    }
    sort(A.begin(), A.end(), cmp);
    vector<int> length(dol);
    int LIS = 0;
    int lo[dol];
    for(int i = 0; i < dol; i++){
      int pos = upper_bound(lo,lo+LIS,A[i].second) - lo;
      lo[pos] = A[i].second;
      if(pos+1 > LIS) LIS=pos+1;
      //printf("pos= %d lis = %d\n",pos,LIS);
    }
    printf("%d\n", LIS);
  }
  return 0;
}*/

