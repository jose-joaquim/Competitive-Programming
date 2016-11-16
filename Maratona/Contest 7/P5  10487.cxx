// http://uva.onlinejudge.org/external/104/10487.html
// Linear Search 
// Runtime : 0.048s
 
// @BEGIN_OF_SOURCE_CODE
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;
 
int sum [1000 * 1000 + 10];
 
int main ()
{
    int n;
    int cases = 0;
 
    while ( scanf ("%d", &n) && n ) {
        int nums [1000 + 10];
 
        for ( int i = 0; i < n; i++ ) scanf ("%d", &nums [i]);
 
        int sum_len = 0;
 
        for ( int i = 0; i < n; i++ ) {
            for ( int j = i + 1; j < n; j++ ) sum [sum_len++] = nums [i] + nums [j];
        }
 
        int m;
        scanf ("%d", &m);
 
        printf ("Case %d:\n", ++cases);
 
        for ( int i = 0; i < m; i++ ) {
            int query;
            scanf ("%d", &query);
            int min_diff = INT_MAX;
            int closest_sum;
 
            for ( int j = 0; j < sum_len; j++ ) {
                int diff = abs (query - sum [j]);
                if ( diff < min_diff ) { min_diff = diff; closest_sum = sum [j];}
            }
 
            printf ("Closest sum to %d is %d.\n", query, closest_sum);
        }
    }
 
    return 0;
}
