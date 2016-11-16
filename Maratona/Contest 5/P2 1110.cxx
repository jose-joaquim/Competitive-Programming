#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	while(n != 0){
		deque<int> Deque; int x;
		for(int i = n; i>0; i--){
			Deque.push_back(i);
		}
		printf("Discarded cards: ");
		while(Deque.size() >= 2){
			printf("%d", Deque.back());
			if(Deque.size() == 2) break;
			else printf(", ");
			Deque.pop_back();
			x = Deque.back();
			Deque.push_front(x);
			Deque.pop_back();
		}
		puts("");
		printf("Remaining card: %d\n", Deque.front());
		scanf("%d", &n);			
	}
	return 0;
}

