//冒泡排序
void BubbleSort(int *a, int n)
{
  int end = 0;
  for (end = n - 1; end >= 0; end--)
  {
    int exchange = 0; //记录该趟冒泡排序是否进行过交换
    int i = 0;
    for (i = 0; i < end; i++)
    {
      if (a[i] > a[i + 1])
      {
        Swap(&a[i], &a[i + 1]);
        exchange = 1;
      }
    }
    if (exchange == 0) //该趟冒泡排序没有进行过交换，已有序
      break;
  }
}
