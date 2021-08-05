#include <stdio.h>
#include <string.h>
int a[100];
int visite[100];
int n;
void dfs(int k)
{
  if (k == n + 1)
  {
    for (int i = 1; i <= n; i++)
      printf("%d ", a[i]);
    printf("\n");
    return;
  }
  for (int j = 1; j <= n; j++)
  {
    if (visite[j] == 0)
    {
      visite[j] = 1;
      a[k] = j; //试探
      dfs(k + 1);
      visite[j] = 0; //回溯
    }
  }
}
int main()
{
  while (~scanf("%d", &n))
  {
    memset(visite, 0, sizeof(visite));
    memset(a, 0, sizeof(a));
    dfs(1);
  }
}
