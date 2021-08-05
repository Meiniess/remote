#include <stdio.h>
#include<stdlib.h>
#include <math.h>
//#include<algorithm>
int arr[27];

int main()
{
  int i;
  arr[1] = 1;
  arr[4] = 1;
  arr[6] = 1;
  for (i = 0; i < 27; i++)
  {
    if (min(min(arr[i - 1], arr[i - 4]), arr[i - 6]) == 0)
    {
      arr[i] = 0;
    }
    else
    {
      arr[i] = min(min(arr[i - 1], arr[i - 4]), arr[i - 6]) + 1;
    }
  }
  printf("%d", arr[26]);
}