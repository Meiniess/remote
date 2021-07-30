//希尔排序
void ShellSort(int *a, int n)
{
  int gap = n;
  while (gap > 1)
  {
    gap = gap / 2; //gap折半
    int i = 0;
    //进行一趟排序
    for (i = 0; i < n - gap; i++)
    {
      int end = i;
      int tmp = a[end + gap];
      while (end >= 0)
      {
        if (tmp < a[end])
        {
          a[end + gap] = a[end];
          end -= gap;
        }
        else
        {
          break;
        }
      }
      a[end + gap] = tmp;
    }
  }
}
