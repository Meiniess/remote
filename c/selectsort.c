//选择排序(一次选一个数)
void SelectSort(int *a, int n)
{
  int i = 0;
  for (i = 0; i < n; i++) //i代表参与该趟选择排序的第一个元素的下标
  {
    int start = i;
    int min = start; //记录最小元素的下标
    while (start < n)
    {
      if (a[start] < a[min])
        min = start; //最小值的下标更新
      start++;
    }
    Swap(&a[i], &a[min]); //最小值与参与该趟选择排序的第一个元素交换位置
  }
}

//选择排序(一次选两个数)
void SelectSort(int *a, int n)
{
  int left = 0;      //记录参与该趟选择排序的第一个元素的下标
  int right = n - 1; //记录参与该趟选择排序的最后一个元素的下标
  while (left < right)
  {
    int minIndex = left; //记录最小元素的下标
    int maxIndex = left; //记录最大元素的下标
    int i = 0;
    //找出最大值及最小值的下标
    for (i = left; i <= right; i++)
    {
      if (a[i] < a[minIndex])
        minIndex = i;
      if (a[i] > a[maxIndex])
        maxIndex = i;
    }
    //将最大值和最小值放在序列开头和末尾
    Swap(&a[minIndex], &a[left]);
    if (left == maxIndex)
    {
      maxIndex = minIndex; //防止最大值位于序列开头，被最小值交换
    }
    Swap(&a[maxIndex], &a[right]);
    left++;
    right--;
  }
}
