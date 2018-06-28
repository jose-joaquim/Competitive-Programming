#include <iostream>
using namespace std;

#define MAX 10002

int swapCnt;
int size;

void sort(int vec[])
{
  int tmp;
  swapCnt = 0;
  bool trocou = true;

  while (trocou)
    {
      trocou = false;
      for (int i = 1; i <= size; i++)
        {
          if (i != vec[i])
            {
              //printf("%d %d %d\n", i, vec[i], vec[vec[i]]);
              swapCnt++;
              tmp = vec[vec[i]];
              vec[vec[i]] = vec[i];
              vec[i] = tmp;
              //printf("troquei %d com %d\n", tmp, vec[vec[i]]);
              trocou = true;
            }
        }
    }
}

int main()
{
  int n;
  int vec[MAX];

  cin >> n;

  for (int i = 0; i < n; i++)
    {
      cin >> size;
      swapCnt = 0;

      for (int j = 1; j <= size; j++)
        {
          cin >> vec[j];
        }
      sort(vec);
      cout << swapCnt << endl;
    }
  return 0;
}
/*
  #include <cstring>
  #include <cstdio>
  #include <iostream>
  #include <vector>
  #include <cmath>

  using namespace std;

  #define len(x) ((int)x.size())

  int main() {
  #ifndef OFF
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #endif

  
  return 0;
  }
*/
